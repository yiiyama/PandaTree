pipeline {
  agent any

  environment {
    SCRAM_ARCH = 'slc6_amd64_gcc530'
    DOSRC = 'source /cvmfs/cms.cern.ch/cmsset_default.sh'
    CMSSW_VERSION = 'CMSSW_8_0_29'
    PANDA_PROD_URL = 'https://github.com/dabercro/PandaProd.git'
    PANDA_PROD_BRANCH = 'jenkins'
    TEST_FILES_DIR = '/home/dabercro/cms/cmssw/CMSSW_8_0_29/src/PandaProd/Producer/cfg'
  }

  stages {
    stage('Report Start') {
      steps {
        withCredentials([usernameColonPassword(credentialsId: 'mitsidekick', variable: 'USERPASS')]) {
          sh '''
             set +x
             if [ ! -z $CHANGE_URL ]
             then
                 # Craft the URL for the github comments API from the PR
                 COMMENT_URL=$(echo $CHANGE_URL | perl -a -F/ -ne 'chomp @F[-1]; print "https://api.github.com/repos/@F[-4]/@F[-3]/issues/@F[-1]/comments"')
                 curl -u $USERPASS -X POST -d '{"body": "Starting tests"}' $COMMENT_URL
             fi
             '''
        }
      }
    }

    stage('Build') {
      steps {

        sh 'ls'

        // Get CMSSW if needed
        sh '''
           if [ ! -d $CMSSW_VERSION ]
           then
               $DOSRC
               scramv1 project CMSSW $CMSSW_VERSION
           fi
           '''    

        sh 'ls $CMSSW_VERSION/src'

        // Make PandaTree directory for us to recursively copy files into
        sh '''
           if [ ! -d $CMSSW_VERSION/src/PandaTree ]
           then
               mkdir $CMSSW_VERSION/src/PandaTree
           fi
           '''

        // Copy all of the files, and the HEAD where we will get the git tag from
        sh 'cp --parents $(git ls-files) $CMSSW_VERSION/src/PandaTree'
        sh 'cp --parents .git/HEAD  $CMSSW_VERSION/src/PandaTree'

        // Install PandaProd and compile
        dir ("${env.CMSSW_VERSION}/src") {

            // Install PandaProd, from scratch
            sh '''
               if [ -d PandaProd ]
               then
                   rm -rf PandaProd
               fi
               git clone -b $PANDA_PROD_BRANCH $PANDA_PROD_URL
               '''

            // Check if we should reinstall everything else
            // If we don't use what's already there, compiling takes much longer
            sh '''
               if [ ! -d PhysicsTools ]
               then
                   $DOSRC
                   eval `scramv1 runtime -sh`
                   PandaProd/Producer/cfg/setuprel.sh
               fi
               '''

            // Compile
            sh '$DOSRC; eval `scramv1 runtime -sh`; scram b -j4'
        }
      }
    }

    stage('Test') {
      steps {
        dir ("${env.CMSSW_VERSION}/src") {
            sh '$DOSRC;  eval `scramv1 runtime -sh`; testpanda $TEST_FILES_DIR/mc.root ${BUILD_TAG}_mc'
            sh '$DOSRC;  eval `scramv1 runtime -sh`; testpanda $TEST_FILES_DIR/data.root ${BUILD_TAG}_data'
        }
      }
    }
  }

  post {
    success {
      withCredentials([usernameColonPassword(credentialsId: 'mitsidekick', variable: 'USERPASS')]) {
        sh '''
           set +x
           if [ ! -z $CHANGE_URL ]
           then
               # Craft the URL for the github comments API from the PR
               COMMENT_URL=$(echo $CHANGE_URL | perl -a -F/ -ne 'chomp @F[-1]; print "https://api.github.com/repos/@F[-4]/@F[-3]/issues/@F[-1]/comments"')
               # Lots of escape strings because Jenkins uses this sh string to generate a .sh file...
               curl -u $USERPASS -X POST --data-binary \"{\\\"body\\\": \\\"Tests passed! Plots here:\\n\\n- http://t3serv001.mit.edu/~${USER}/relval/?d=${BUILD_TAG}_data\\n- http://t3serv001.mit.edu/~${USER}/relval/?d=${BUILD_TAG}_mc\\\"}\" $COMMENT_URL
           fi
           '''
      }
    }

    failure {
      withCredentials([usernameColonPassword(credentialsId: 'mitsidekick', variable: 'USERPASS')]) {
        sh '''
           set +x
           if [ ! -z $CHANGE_URL ]
           then
               # Craft the URL for the github comments API from the PR
               COMMENT_URL=$(echo $CHANGE_URL | perl -a -F/ -ne 'chomp @F[-1]; print "https://api.github.com/repos/@F[-4]/@F[-3]/issues/@F[-1]/comments"')
               curl -u $USERPASS -X POST -d '{"body": "Tests failed..."}' $COMMENT_URL
           fi
           '''
      }
    }
  }
}
