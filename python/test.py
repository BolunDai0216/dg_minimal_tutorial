import dynamic_graph_manager_cpp_bindings
import numpy as np


def main():
    """
    Need to first set the Python path:
    export PYTHONPATH=$PYTHONPATH:/home/mocap/dgm-ws/install/dynamic_graph_manager/lib/python3.8/site-packages
    """
    config_file = (
        "/home/mocap/Documents/dg_minimal_tutorial/config/dg_minimal_tutorial.yaml"
    )
    head = dynamic_graph_manager_cpp_bindings.DGMHead(config_file)

    head.read()
    value = head.get_sensor("value")
    print(f"Value in shared memory is: {value}")

    head.set_control("new_value", np.array([1.0, 2.0]))
    head.write()


if __name__ == "__main__":
    main()
