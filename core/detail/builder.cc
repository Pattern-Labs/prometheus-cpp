#include "prometheus/detail/builder.h"

#include "prometheus/counter.h"
#include "prometheus/gauge.h"
#include "prometheus/histogram.h"
#include "prometheus/info.h"
#include "prometheus/registry.h"
#include "prometheus/summary.h"

namespace prometheus {

namespace detail {

template <typename T>
Builder<T>& Builder<T>::Labels(const ::prometheus::Labels& labels) {
  labels_ = labels;
  return *this;
}

template <typename T>
Builder<T>& Builder<T>::Name(const std::string& name) {
  name_ = name;
  return *this;
}

template <typename T>
Builder<T>& Builder<T>::Help(const std::string& help) {
  help_ = help;
  return *this;
}

template <typename T>
Family<T>& Builder<T>::Register(Registry& registry) {
  return registry.Add<T>(name_, help_, labels_);
}

template class Builder<Counter>;
template class Builder<Gauge>;
template class Builder<Histogram>;
template class Builder<Info>;
template class Builder<Summary>;

}  // namespace detail

detail::Builder<Counter> BuildCounter() { return {}; }
detail::Builder<Gauge> BuildGauge() { return {}; }
detail::Builder<Histogram> BuildHistogram() { return {}; }
detail::Builder<Info> BuildInfo() { return {}; }
detail::Builder<Summary> BuildSummary() { return {}; }

}  // namespace prometheus
