## Table of Contents
- [Notebooks](#Notebooks)
- [Contributors](#contributors)
- [Setup Instructions](#setup-instructions)
- [How to Contribute](#how-to-contribute)
- [References](#references)


## Notebooks

1. [Introduction to Classes](./Notebooks/01_Classes/): Getting started with Classes. <br><br>
2. [Abstract Data Type and Inheritance](./Notebooks/02_ADT_and_Inheritance): Understanding and applying OOP concepts. <br><br>

Feel free to explore the folders above for detailed Jupyter Notebooks on each programming topic.

## Contributors

We appreciate contributions from the following individuals:

- [Mahdi Porheydari](https://github.com/MahdiPorheydarii)
- [Kazem Forghani](https://github.com/k-forghani)
- [Sahar Pourghasemi](https://github.com/saharpgh)
- [Alireza Khadem](https://github.com/Alireza-Khadem)
- [Mahdi Aghaei](https://github.com/maghaei33)


## Setup Instructions
Setting up WSL, Miniconda, xeus-cling, and Jupyter on Windows.

### Step 1: Install WSL (Windows Subsystem for Linux)

1. Open PowerShell as Administrator and run the following command to enable WSL:

   ```powershell
   wsl --install
   ```
2. Set up your Linux user info:
   once you have installed WSL, you will need to create a user account and password for your newly installed Linux distribution.

### Step 2: Install and Activate Miniconda
1. Download the Miniconda installer for linux:
   ```bash
   mkdir -p ~/miniconda3
   wget https://repo.anaconda.com/miniconda/Miniconda3-latest-Linux-x86_64.sh -O ~/miniconda3/miniconda.sh
   ```
2. Run the installer script:
    ```bash
    bash ~/miniconda3/miniconda.sh -b -u -p ~/miniconda3
    rm -rf ~/miniconda3/miniconda.sh
    ```
3. Activate Miniconda:
    ```bash
    ~/miniconda3/bin/conda init bash
    conda config --set auto_activate_base false
    ```
### Step 3: Create a Conda Environment and Install Libraries:
1. Create an environment:
    ```bash
    conda create -n cpp-notebooks -y
    ```
2. Activate the environment:
    ```bash
    conda activate cpp-notebooks
    ```
3. Install Jupyter and Xeus-cling in the environment:
    ```bash
    conda install jupyter xeus-cling -c conda-forge -y
    ```
### Step 4: Start Jupyter
1. Start Jupyter server:
    ```bash
    jupyter notebook
    ```
2. Open your web browser and navigate to http://localhost:8888. You should see the Jupyter Notebook interface.
3. To access Jupyter from outside WSL, use the IP address of your Windows machine (you can find it using the ipconfig command in a Windows command prompt).

**Congratulations! You have successfully set up WSL, Miniconda, xeus-cling, and Jupyter on your Windows machine.**




## How to Contribute

We welcome and appreciate contributions from the community. If you want to fix bugs, address issues, or add new content to the lectures, follow these steps:

1. Fork the repository.
2. Create a new branch for your contributions.
3. Make your changes and commit them.
4. Push to your branch.
5. Open a pull request describing your changes.

Please make sure to provide a clear and concise explanation of your changes in the pull request description. If your contribution addresses any existing issues, reference them in your pull request.

Before submitting a pull request, ensure that your code follows best practices, is well-documented, and includes relevant tests if applicable.

### Code Style

Follow the existing code style to maintain consistency across the repository.

### Issues and Bugs

If you find any issues or bugs in the code, please open an issue to report it. Include a detailed description of the problem, steps to reproduce, and any additional information that might be helpful.

### Feature Requests

If you have ideas for new features or improvements, feel free to open an issue to discuss them.

Thank you for contributing to the Advanced Programming (AP) Lectures Repository!

## References

All content used in these lectures is sourced from the following reference:

Walter J. Savitch. Problem Solving with C++, Tenth Edition. 2018.