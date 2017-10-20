/**
 * Copyright (C) 2016 AUTH-ARL
 */

#ifndef ATI_SENSOR_ATI_SENSOR_H
#define ATI_SENSOR_ATI_SENSOR_H

#include <autharl_core/robot/sensor.h>
#include <ati_sensor/ft_sensor.h>
#include <ros/ros.h>
#include <memory>
#include <vector>
#include <string>


namespace ati
{
namespace sensor
{
class Sensor : public arl::robot::Sensor
{
public:
  explicit Sensor(const std::string& name = "Ati Sensor", const std::string& frame_id = "ati_sensor");

  void getData(KDL::JntArray &output);
  void getData(arma::vec &output);
  void getData(Eigen::VectorXd &output);
  template <typename T> void getDataTemplate(T &output)
  {
    static float temp[6];
    output.resize(6);
    sensor_->getMeasurements(temp);  // ,rdt,ft);
    for (size_t i = 0; i < 6; i++) {
      output(i) = temp[i];
    }
  }

  bool isOk();

private:
  std::shared_ptr<ati::FTSensor> sensor_;

};
}  // namespace sensor
}  // namespace api

#endif  // ATI_SENSOR_ATI_SENSOR_H
