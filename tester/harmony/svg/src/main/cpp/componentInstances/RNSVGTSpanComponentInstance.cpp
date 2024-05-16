#include "RNSVGTSpanComponentInstance.h"
#include "Props.h"
#include <react/renderer/core/ConcreteState.h>
#include <sstream>
#include <SvgTSpan.h>

namespace rnoh {
namespace svg {

RNSVGTSpanComponentInstance::RNSVGTSpanComponentInstance(Context context) : CppComponentInstance(std::move(context)) {
    SetSvgNode(m_svgTSpan);
}

void RNSVGTSpanComponentInstance::onPropsChanged(SharedConcreteProps const &props) {
     CppComponentInstance::onPropsChanged(props);
    // TODO: move ArkUINode to base class and use template function
    if (!props->responsible) {
        m_svgArkUINode.setHitTestMode(facebook::react::PointerEventsMode::None);
    } else {
        m_svgArkUINode.setHitTestMode(facebook::react::PointerEventsMode::Auto);
    }
     GetSvgNode()->UpdateCommonProps(props);
    m_svgTSpan->content_ = props->content;

    m_svgTSpan->UpdateFontProps(props);
    m_svgTSpan->UpdateTextProps(props);
}

SvgArkUINode &RNSVGTSpanComponentInstance::getLocalRootArkUINode() { return m_svgArkUINode; }
    void RNSVGTSpanComponentInstance::onChildInserted(ComponentInstance::Shared const &childComponentInstance, std::size_t index){
        auto child = std::dynamic_pointer_cast<SvgHost>(childComponentInstance);
        if (!child) {
            return;
        }
        OnChildInsertCommon(std::dynamic_pointer_cast<SvgHost>(child));
    }

} // namespace svg
} // namespace rnoh
