#include "dynamic_graph_manager/dynamic_graph_manager.hpp"

namespace dg_minimal_tutorial {

class DGMinimalTutorial: public dynamic_graph_manager::DynamicGraphManager {
    public:
        DGMinimalTutorial();
        ~DGMinimalTutorial();
        
        void initialize_hardware_communication_process();
        void get_sensors_to_map(dynamic_graph_manager::VectorDGMap& map);
        void set_motor_controls_from_map(const dynamic_graph_manager::VectorDGMap& map);
};

}
