// Copyright (c) 2018 leosocy. All rights reserved.
// Use of this source code is governed by a MIT-style license
// that can be found in the LICENSE file.

#include "test_base.h"
#include "handler/handler.h"

namespace {

using cv::Mat;

using rpr::Status;

class FilterTestFixture : public RobustPalmRoiTestFixtureBase {
 public:
  FilterTestFixture() : RobustPalmRoiTestFixtureBase(0.2) {}
};


TEST_F(FilterTestFixture, test_gaussian_filter) {
  auto filter = rpr::HandlerFactory::instance().GetHandler("GaussianFilter");
  auto status = filter->Handle(invalid_palm_);
  EXPECT_EQ(status.code(), Status::kLoadImageError);

  status = filter->Handle(complex_env_palm_);
  EXPECT_EQ(status.code(), Status::kOk);
}

}   // namespace
