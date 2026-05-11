# ROMS Idealized Setup
## Read this before you do anything with this repo

* Clone this git repo to your home at the hpc you work at or your laptop by typing the following command in the terminal:
    ```
    git clone git@github.com:norkyst/ROMS-idealized-setup.git
    ```
* Download ROMS from Github
    * https://github.com/myroms/roms (original ROMS, use either the develop branch or main branch).
    * https://github.com/taleMET/roms-seaice (ROMS seaice fork by Tale).
* Compile:
    * In the terminal, go to the directory where you cloned this repo:
    ```
    cd ROMS-idealized-setup
    ```
    * Open the compile script `build_roms.sh` in a text editor, and make sure that `export MY_ROMS_SRC=${MY_ROOT_DIR}/roms` points to where the ROMS source you just downloaded is located.
    * To change the ROMS settings (for example to turn off sea ice), define or undefine in the header file `include/idealized.h`. This must be done before compiling.
    * Before compiling, it could be necessary to remove the directory `Build_romsM` . This directory is created by the compile script, and contains temporary files used in the compilation.
    * Update the modules.sh file for the hpc system you work on. Ask you local sysadmin for help to find the modules located in the modules.sh file.
    * Compile by the following commands:
    ```
    source modules.sh
    ./build_roms.sh -j 12
    ```
    * Check that a new executable (a `romsM` file) is created, by for example using the command `ls -l` and see that the `romsM` file is new.
* Run:
    * Before you can run this roms test, you need to download the necessary forcing files. These can be found at INSERT PATH TO THREDDS HERE. Download these to your hpc or computer.
    * Runtime input settings are located in the `.in`-files in the directory `in_files`. In the file `in_files/roms_202504.in`, among many other things, the paths to the forcing files are set.
    * You need to update the paths VARNAME, GRDNAME, ININAME, BRYNAME, CLMNAME, NUDNAME, SSFNAME, TIDENAME, FRCNAME so they point to the files you just downloaded.
    * You also need to update the output paths in `in_files/roms_202504.in`. Update the paths RSTNAME, HISNAME, AVGNAME, DIANAME and STANAME to where you want your output to be saved. 
    * To run the roms test, you should create a submission script and submit this to your supercomputer. Ask your local system administrator for help writing this for your specific computer. An example of how the roms program can be run is to execute the following command:
    ```
    mpprun romsM in_files/roms_202504.in > /path/to/a/log_file
    ```
