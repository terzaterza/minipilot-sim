#pragma once

#include "drivers/bridge/bridge.hpp"
#include "emblib/driver/sensor/accelerometer.hpp"

namespace mpsim {

class accelerometer_pb : public emblib::accelerometer {

public:
    explicit accelerometer_pb(bridge& bridge) :
        m_bridge(bridge)
    {}

    bool probe() noexcept override
    {
        return true;
    }

    bool is_data_available() noexcept override
    {
        return true;
    }

    bool read_axis(axis_e axis, float& out_g) noexcept override
    {
        return false;
    }

    float get_noise_density() const noexcept override
    {
        return 0;
    }

    bool read_all_axes(float (&out_data)[3]) noexcept override;

private:
    bridge& m_bridge;

};

}