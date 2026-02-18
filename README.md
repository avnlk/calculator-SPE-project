# Scientific Calculator (C++17)

A menu-driven scientific calculator implemented in C++ with support for:

- Square root: $\sqrt{x}$
- Factorial: $x!$
- Natural logarithm: $\ln(x)$
- Power: $x^b$

The project includes:

- Unit tests with GoogleTest
- Docker multi-stage build for a lightweight runtime image
- Jenkins pipeline for build, test, image publish, and deployment
- Ansible playbooks for deployment and validation

## Project Structure

```text
.
├── CMakeLists.txt
├── Dockerfile
├── Jenkinsfile
├── include/
│   ├── factorial_func.h
│   ├── ln_func.h
│   ├── power_func.h
│   └── sqrt_func.h
├── src/
│   ├── factorial_func.cpp
│   ├── ln_func.cpp
│   ├── main.cpp
│   ├── power_func.cpp
│   └── sqrt_func.cpp
├── tests/
│   ├── test_factorial.cpp
│   ├── test_ln.cpp
│   ├── test_power.cpp
│   └── test_sqrt.cpp
└── ansible/
		├── deploy.yml
		├── inventory.ini
		└── validate_calculator.yml
```

## Prerequisites

### Local build and test

- C++ compiler with C++17 support (`g++` recommended)
- CMake 3.10+
- Make
- GoogleTest development package

Example (Ubuntu/Debian):

```bash
sudo apt update
sudo apt install -y build-essential cmake libgtest-dev
```

### Container and deployment

- Docker
- Ansible
- Ansible collection: `community.docker`

Install the Ansible collection:

```bash
ansible-galaxy collection install community.docker
```

## Build and Run (Local)

```bash
mkdir -p build
cd build
cmake ..
make
./calculator
```

The calculator starts an interactive menu and runs until you select `Exit`.

## Run Unit Tests

From the `build` directory:

```bash
./runTests
```

Or via CTest:

```bash
ctest --output-on-failure
```

## Function Behavior and Validation Rules

- `squareRoot(x)`
	- Valid for $x \ge 0$
	- Throws `std::invalid_argument` for negative input
- `factorial(n)`
	- Valid for integers $n \ge 0$
	- Throws `std::invalid_argument` for negative input
- `naturalLog(x)`
	- Valid for $x > 0$
	- Throws `std::invalid_argument` for non-positive input
- `power(base, exp)`
	- Uses `std::pow(base, exp)`

## Docker

The Dockerfile uses a multi-stage build:

1. **Builder stage** compiles the calculator with tests disabled (`-DBUILD_TESTS=OFF`).
2. **Runtime stage** copies only the compiled `calculator` binary into a small Alpine image.

Build image:

```bash
docker build -t avnlk/calculator:latest .
```

Run container interactively:

```bash
docker run --rm -it avnlk/calculator:latest
```

## Jenkins Pipeline

`Jenkinsfile` defines these stages:

1. Checkout
2. Build (`cmake`, `make`)
3. Test (`./runTests`)
4. Docker Build
5. Docker Push (`avnlk/calculator:latest`)
6. Deploy (Ansible)
7. Validation (Ansible)

### Jenkins requirements

- Docker available on Jenkins agent
- Ansible available on Jenkins agent
- Jenkins credential with ID: `dockerhub-cred`
- Permission to access/push Docker Hub image: `avnlk/calculator:latest`

## Ansible Deployment and Validation

Inventory currently targets local host:

```ini
[app_servers]
localhost ansible_connection=local
```

Deploy container:

```bash
ansible-playbook -i ansible/inventory.ini ansible/deploy.yml
```

Validate deployment:

```bash
ansible-playbook -i ansible/inventory.ini ansible/validate_calculator.yml
```

Validation playbook runs the calculator inside the container using sample input and asserts expected output is present.

## Notes

- Factorial return type is `unsigned long long`; very large inputs can overflow.
- Input parsing is interactive and expects valid numeric values.

## AI Usage

- AI assistance (GitHub Copilot) was used to draft and refine this `README.md`.
- Commands, file paths, and pipeline/deployment details were cross-checked against the repository before finalizing.
- Final review and approval of the documentation was done manually by the project author.

## Author

Lokesh Aravapalli (avnlk)