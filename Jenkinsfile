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
    }

    post {
        always {
            echo 'Pipeline finished.'
        }
        failure {
            echo 'Build or tests failed!'
        }
    }
}

