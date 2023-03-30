# dg_minimal_tutorial

## Installation

```console
mkdir build && cd build
cmake ..
cmake --build .
cmake --install . --prefix "/home/mocap/Documents/dg_minimal_tutorial/install"
```

## Usage

In the root directory run the generated executable

```console
./install/lib/dg_minimal_tutorial/dg_minimal_tutorial_main
```

Then, open another terminal, and run the Python test file

```console
python3 python/test.py
```

you should see an output similar to

```console
Loading parameters from /home/mocap/Documents/dg_minimal_tutorial/config/dg_minimal_tutorial.yaml
Seting up cond_var
Value in shared memory is: [1. 2.]
```

in the Python console.