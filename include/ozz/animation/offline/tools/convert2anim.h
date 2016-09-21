//----------------------------------------------------------------------------//
//                                                                            //
// ozz-animation is hosted at http://github.com/guillaumeblanc/ozz-animation  //
// and distributed under the MIT License (MIT).                               //
//                                                                            //
// Copyright (c) 2015 Guillaume Blanc                                         //
//                                                                            //
// Permission is hereby granted, free of charge, to any person obtaining a    //
// copy of this software and associated documentation files (the "Software"), //
// to deal in the Software without restriction, including without limitation  //
// the rights to use, copy, modify, merge, publish, distribute, sublicense,   //
// and/or sell copies of the Software, and to permit persons to whom the      //
// Software is furnished to do so, subject to the following conditions:       //
//                                                                            //
// The above copyright notice and this permission notice shall be included in //
// all copies or substantial portions of the Software.                        //
//                                                                            //
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR //
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,   //
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL    //
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER //
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING    //
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER        //
// DEALINGS IN THE SOFTWARE.                                                  //
//                                                                            //
//----------------------------------------------------------------------------//

#ifndef OZZ_OZZ_ANIMATION_OFFLINE_TOOLS_CONVERT2ANIM_H_
#define OZZ_OZZ_ANIMATION_OFFLINE_TOOLS_CONVERT2ANIM_H_

#include "ozz/base/containers/vector.h"
#include "ozz/base/containers/string.h"

#include "ozz/animation/offline/raw_animation.h"

namespace ozz {
namespace animation {

class Skeleton;

namespace offline {

class AnimationConverter {
 public:
  int operator ()(int _argc, const char** _argv);

 protected:

  struct NamedAnimation {
    ozz::String::Std name;
    ozz::animation::offline::RawAnimation animation;
  };
  typedef ozz::Vector<NamedAnimation>::Std NamedAnimations;

 private:

  virtual bool Import(const char* _filename,
                      const ozz::animation::Skeleton& _skeleton,
                      float _sampling_rate,
                      NamedAnimations* _animations) = 0;
};
}  // offline
}  // animation
}  // ozz
#endif  // OZZ_OZZ_ANIMATION_OFFLINE_TOOLS_CONVERT2ANIM_H_
