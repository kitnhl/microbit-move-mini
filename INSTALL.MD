**This was an incomplete attempt at settting the environment up from scratch.** 

## To avoid all these troubles, use the [micro:bit Toolchain Docker](https://github.com/carlosperate/docker-microbit-toolchain).

1. Install Homebrew
    - `/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"`
    - `(echo; echo 'eval "$(/opt/homebrew/bin/brew shellenv)"') >> /Users/kit/.zprofile`
    - `eval "$(/opt/homebrew/bin/brew shellenv)"`
2. Tap the ARMmbed brew formulae
    - `brew tap ARMmbed/homebrew-formulae`
3. Install everything that yotta needs
    - `brew install python cmake ninja arm-none-eabi-gcc`
4. Install yotta
    - `python3 -m pip install --upgrade pip`
    - `brew  install openssl@1.1`
    - `export LDFLAGS="-L/opt/homebrew/opt/openssl@1.1/lib"`
    - `export CPPFLAGS="-I/opt/homebrew/opt/openssl@1.1/include"`
    - `pip3 install PyYAML==5.3.1 yotta`
    - `export PATH=$PATH:/Users/kit/Library/Python/3.9/bin`
5. Install srecord
    - `brew install srecord`
6. Fetch the example project
    - `git clone https://github.com/lancaster-university/microbit-samples`
    - `cd microbit-samples`
7. Set Python version to 3.6.8
    1. Make a Python virtual environment
        - `python -m venv ubit-venv`
        - `source ubit-venv/bin/activate`
    1. Install brew
        - `arch -x86_64 /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"`
    2. Configure your shell's environment (in my case zsh)
        - `echo 'eval "$(/usr/local/bin/brew shellenv)"' >> ~/.zshrc`
        - `exec $SHELL -l`
        - `source ubit-venv/bin/activate`
    3. Install the recommended dependencies:
        - `arch -x86_64 brew install openssl readline sqlite3 xz zlib`
    4. Install Pyenv with brew
        - `arch -x86_64 brew install pyenv`
    5. Set up shell environment for pyenv
        - `echo 'export PYENV_ROOT="$HOME/.pyenv"' >> ~/.zshrc`
        - `echo '[[ -d $PYENV_ROOT/bin ]] && export PATH="$PYENV_ROOT/bin:$PATH"' >> ~/.zshrc`
        - `echo 'eval "$(pyenv init -)"' >> ~/.zshrc`
        - `exec $SHELL -l`
        - `source ubit-venv/bin/activate`
    6. Add environment variables
        - `export LDFLAGS="-L/usr/local/opt/zlib/lib"`
        - `export CPPFLAGS="-I/usr/local/opt/zlib/include"`
        - `export LDFLAGS="-L/usr/local/opt/openssl@3/lib"`
        - `export CPPFLAGS="-I/usr/local/opt/openssl@3/include"`
    7. Install the required Python version with patch
        - `arch -x86_64 pyenv install --patch 3.6.8 <<(curl -sSL https://github.com/python/cpython/commit/8ea6353.patch\?full_index\=1)`
    8. Switch shell to new Python version
        - `pyenv shell 3.6.15`
        - `pyenv which python3`
        - `python3 -V`   
8. Set the yotta target
    - `yotta target bbc-microbit-classic-gcc@https://github.com/lancaster-university/yotta-target-bbc-microbit-classic-gcc`
9. Attempt to build the project
    - Replace `soft_unicode` with `soft_str` in `/Users/[kit]/Library/Python/3.9/lib/python/site-packages/jinja2/filters.py|runtime.py`
    - Comment out all `@fsutils.dropRootPrivs` in `/Users/[kit]/Library/Python/3.9/lib/python/site-packages/yotta/pack.py|target.py`
    - Run `yotta build`, which will likely still yield errors...
