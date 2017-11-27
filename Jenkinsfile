pipeline {
  agent any

  environment {
    SCRAM_ARCH = 'slc6_amd64_gcc530'
    DOSRC = 'source /cvmfs/cms.cern.ch/cmsset_default.sh'
    CMSSW_VERSION = 'CMSSW_8_0_29'
    PANDA_PROD_USER = 'dabercro'
    PANDA_PROD_BRANCH = 'jenkins-clean'
  }

  stages {
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
      }
    }

    stage('Test') {
      steps {
        dir ("${env.CMSSW_VERSION}/src") {
            sh '''
               $DOSRC
               eval `scramv1 runtime -sh`
               for f in /mnt/hadoop/scratch/jenkins/panda/$PANDA_PROD_USER/PandaProd/$PANDA_PROD_BRANCH/*
               do
                   BASE=$(echo $f | perl -e '/\\/([\\w-]+)\\.root/ && print "$1"')
                   testpanda $f ${JOB_NAME}/${BUILD_NUMBER}/$(tail -n1 $HOME/miniaod/$BASE.txt)
               done
               '''
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
               curl -u $USERPASS -X POST --data-binary \"{\\\"body\\\": \\\"Tests passed! Plots here:\\n\\n- http://t3serv001.mit.edu/~${USER}/relval/?d=${JOB_NAME}/${BUILD_NUMBER}\\\"}\" $COMMENT_URL
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
