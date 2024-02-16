# Setting up WSL, Miniconda, xeus-cling, and Jupyter on Windows

## Step 1: Install WSL (Windows Subsystem for Linux)

1. Open PowerShell as Administrator and run the following command to enable WSL:

   ```powershell
   wsl --install
   ```
2. Set up your Linux user info:
   once you have installed WSL, you will need to create a user account and password for your newly installed Linux distribution.

## Step 2: Install and Activate Miniconda
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
## Step 3: Create a Conda Environment and Install Libraries:
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
## Step 4: Start Jupyter
1. Start Jupyter server:
    ```bash
    jupyter notebook
    ```
2. Open your web browser and navigate to http://localhost:8888. You should see the Jupyter Notebook interface.
3. To access Jupyter from outside WSL, use the IP address of your Windows machine (you can find it using the ipconfig command in a Windows command prompt).

**Congratulations! You have successfully set up WSL, Miniconda, xeus-cling, and Jupyter on your Windows machine.**

