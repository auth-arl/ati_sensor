/**
 * Copyright (C) 2016 AUTH-ARL
 */

#include <ati_sensor/ati_sensor.h>
#include <iostream>
#include <string>

#define JOINT_SIZE 7

namespace ati
{
  namespace sensor
  {
    Sensor::Sensor(const std::string& name, const std::string& frame_id) :
        arl::robot::Sensor(name)
    {
      std::cout << "Creating sensor" << std::endl;
//      sensor_ = std::make_shared<ati::FTSensor>();
      sensor_.reset(new ati::FTSensor());

      std::cout << "Setting timeout to 1.0 sec" << std::endl;
      sensor_->setTimeout(1.0);

      std::cout << "Initializing sensor" << std::endl;
      sensor_->init("192.168.2.1");

      std::cout << "Setting sensor bias" << std::endl;
      sensor_->setBias();

      this->frame_id = frame_id;

      type = FT_SENSOR;
    }

    void Sensor::getData(KDL::JntArray &output)
    {
      getDataTemplate(output);
    }
    void Sensor::getData(arma::vec &output)
    {
      getDataTemplate(output);
    }
    void Sensor::getData(Eigen::VectorXd &output)
    {
      getDataTemplate(output);
    }

    bool Sensor::isOk()
    {
      return true;
    }
  }  // namespace sensor
}  // namespace ati
