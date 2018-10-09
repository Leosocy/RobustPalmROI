/****************************************************************************\
 * Created on Tue Oct 09 2018
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

#ifndef ROBUST_PALM_ROI_APP_HANDLERS_BINARIZER_H_
#define ROBUST_PALM_ROI_APP_HANDLERS_BINARIZER_H_

#include "handlers/handler.h"

namespace rpr {

class Binarizer : public Handler {
 public:
  virtual Status Handle(const cv::Mat& orig, cv::Mat* res);

 protected:
  virtual Status Binary(const cv::Mat& orig, cv::Mat* res) = 0;
};

inline Status Binarizer::Handle(const cv::Mat& orig, cv::Mat* res) {
  assert (res != NULL);
  if (orig.channels() != 3 && orig.channels() != 1) {
    return Status::LoadImageError("Original palm image must be colored or grayscale.");
  }
  return Binary(orig, res);
}


class OtsuBinarizer : public Binarizer {
 private:
  virtual Status Binary(const cv::Mat& orig, cv::Mat* res);
};

}   // namespace rpr

#endif  // ROBUST_PALM_ROI_APP_HANDLERS_BINARIZER_H_