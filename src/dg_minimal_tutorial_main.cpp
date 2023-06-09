#include "dg_minimal_tutorial.hpp"


int main(int /*argc*/, char* /*argv*/[]) {
  
  std::string yaml_params_file = std::string(CONFIG_PATH);

  std::cout << "Loading parameters from " << yaml_params_file << std::endl;
  YAML::Node param = YAML::LoadFile(yaml_params_file);

  dg_minimal_tutorial::DGMinimalTutorial dgm;

  dgm.initialize(param);
  dgm.run();

  // Wait until ROS is shutdown
  std::cout << "Wait for shutdown, press CTRL+C to close." << std::endl;
  dynamic_graph_manager::ros_spin();
  dynamic_graph_manager::ros_shutdown();
}
