/****************************************************************************\
 * Created on Wed Oct 10 2018
 * 
 * The MIT License (MIT)
 * Copyright (c) 2018 leosocy
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the ",Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED ",AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
\*****************************************************************************/

#include "test_base.h"
#include "handlers/binarizer.h"
#include "handlers/adjuster.h"

namespace {

using cv::Mat;

using rpr::Status;
using rpr::OtsuBinarizer;
using rpr::RemoveNoiseAdjuster;

class AdjusterTestFixture : public RobustPalmRoiTestFixtureBase {
 public:
  AdjusterTestFixture() : RobustPalmRoiTestFixtureBase(0.2) {}
};


TEST_F(AdjusterTestFixture, test_remove_noise_adjuster) {
  RemoveNoiseAdjuster adjuster;
  auto status = adjuster.Handle(perfect_palm_, &perfect_palm_);
  EXPECT_EQ(status.code(), Status::kLoadImageError);

  cv::Mat res;
  OtsuBinarizer binarizer;
  binarizer.Handle(perfect_palm_, &res);
  status = adjuster.Handle(res, &res);
  EXPECT_EQ(status.code(), Status::kOk);
}

}