from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.substitutions import ThisLaunchFileDir
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription(
        [
            IncludeLaunchDescription(
                PythonLaunchDescriptionSource(
                    [ThisLaunchFileDir(), "/start_dg_minimal_tutorial.launch.py"]
                )
            ),
            Node(
                package="dg_minimal_tutorial",
                node_executable="dg_minimal_tutorial_main",
                output="screen",
                prefix=["xterm -hold -e"],
            ),
        ]
    )
