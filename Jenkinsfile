pipeline {
    agent any

    environment {
        DOCKER_IMAGE = "avnlk/calculator:latest"
        BUILD_DIR = "build"
        LANG = "en_US.UTF-8"
        LC_ALL = "en_US.UTF-8"
    }
    
    stages {
        stage('Checkout') {
            steps {
                git branch: 'main', url: 'https://github.com/avnlk/calculator-SPE-project.git'
            }
        }

        stage('Build') {
            steps {
                sh '''
                # Cleanup previous build
                rm -rf $BUILD_DIR
                mkdir $BUILD_DIR
                cd $BUILD_DIR
                cmake ..
                make
                '''
            }
        }

        stage('Test') {
            steps {
                sh '''
                cd $BUILD_DIR
                ./runTests
                '''
            }
        }

        stage('Docker Build') {
            steps {
                sh '''
                docker rmi -f $DOCKER_IMAGE || true
                docker build -t $DOCKER_IMAGE .
                '''
            }
        }

        stage('Docker Push') {
            steps {
                withCredentials([usernamePassword(credentialsId: 'dockerhub-cred', usernameVariable: 'DOCKER_USER', passwordVariable: 'DOCKER_PASS')]) {
                    sh '''
                    echo $DOCKER_PASS | docker login -u $DOCKER_USER --password-stdin
                    docker push $DOCKER_IMAGE
                    '''
                }
            }
        }

        stage('Deploy') {
            steps {
                sh 'ansible-playbook -i ansible/inventory.ini ansible/deploy.yml'
            }
        }
        
        stage('Validation') {
            steps {
                sh 'ansible-playbook ansible/validate_calculator.yml -i ansible/inventory.ini'
            }
        }

    }

    post {
        always {
            echo 'Pipeline finished.'
        }

        success {
            mail to: 'lokeshkumar.aravapalli@iiitb.ac.in',
                 subject: "Pipeline Success: ${env.JOB_NAME}",
                 body: "Build, test, and Docker deployment successful."
        }

        failure {
            mail to: 'lokeshkumar.aravapalli@iiitb.ac.in',
                 subject: "Pipeline Failed: ${env.JOB_NAME}",
                 body: "Check Jenkins logs for details."
        }
    }
}
