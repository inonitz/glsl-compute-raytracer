#include "context.hpp"
#include "util/vec2.hpp"
#include <awc2/C/awc2.h>
#include <util/marker2.hpp>


void PVMTransform::create(
    f32 fieldOfView,
    f32 nearClippingPlane,
    f32 farClippingPlane,
    util::math::vec3f const& initialPosition,
    util::math::vec3f const& initialDirection
) {
    auto vpsize = awc2getCurrentContextViewport();mark(); 
    m_persp.create({ 
        __scast(f32, vpsize.x) / __scast(f32, vpsize.y),
        fieldOfView, 
        nearClippingPlane, 
        farClippingPlane 
    });mark(); 
    m_view.create(
        initialPosition, 
        initialDirection, 
        { 7.5f, 1.5f }
    );mark(); 
    return;
}


void PVMTransform::onUpdate(f32 dt)
{
    m_view.onUpdate(dt);
    return;
}


void PVMTransform::recalculateProjection()
{
    m_persp.recalculate();
    util::math::inv_perspective(m_persp.constref(), m_data.invPerspective);
    return;
}


void PVMTransform::writeFinalData(CameraTransformV2& in)
{
    m_data.position = m_view.position();
    util::math::inverseSimd(m_view.constref(), m_data.invView);
    memcpy(__rcast(u8*, &in), __rcast(u8*, &m_data), sizeof(CameraTransformV2));
    return;
}