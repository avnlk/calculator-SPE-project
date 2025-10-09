pipeline {
    agent any

    stages {
        stage('Checkout') {
            steps {
		git branch: 'main', url: 'https://github.com/avnlk/calculator-SPE-project.git'
            }
        }

        stage('Build') {
            steps {
                sh '''
                rm -rf build
                mkdir build
                cd build
                cmake ..
                make
                '''
            }
        }

        stage('Test') {
            steps {
                sh '''
                cd build
                ctest --output-on-failure
                '''
            }
        }

        stage('Docker Build') {
            steps {
                sh 'docker build -t avnlk/calculator:latest .'
            }
        }

        stage('Docker Push') {
            steps {
                withCredentials([usernamePassword(credentialsId: 'dockerhub-cred', usernameVariable: 'DOCKER_USER', passwordVariable: 'DOCKER_PASS')]) {
                    sh '''
                    echo $DOCKER_PASS | docker login -u $DOCKER_USER --password-stdin
                    docker push avnlk/calculator:latest
                    '''
                }
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
                body: "Build and deployment successful."
        }
        failure {
            mail to: 'lokeshkumar.aravapalli@iiitb.ac.in',
                 subject: "Pipeline Failed: ${env.JOB_NAME}",
                 body: "Check Jenkins logs for details."
        }
    }
}
    
