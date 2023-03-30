#include "dg_minimal_tutorial.hpp"
#include <iostream>

namespace dg_minimal_tutorial{

DGMinimalTutorial::DGMinimalTutorial() : dynamic_graph_manager::DynamicGraphManager()
{
}

DGMinimalTutorial::~DGMinimalTutorial()
{
}

void DGMinimalTutorial::initialize_hardware_communication_process() {
    std::cout << "Initialized Hardware Communication Process" << std::endl;
}

void DGMinimalTutorial::get_sensors_to_map(dynamic_graph_manager::VectorDGMap& map) {
    map["value"](0) = 1;
    map["value"](1) = 2;
}

void DGMinimalTutorial::set_motor_controls_from_map(const dynamic_graph_manager::VectorDGMap& map) {
    dynamicgraph::Vector value = map.at("new_value");   
    // std::cout << "New value is: (" << value[0] << ", " << value[1] << ")" << std::endl;
}

}
