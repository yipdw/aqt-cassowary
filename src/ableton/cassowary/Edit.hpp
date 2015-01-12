// Copyright: 2014, Ableton AG, Berlin, all rights reserved
//
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use, copy,
// modify, merge, publish, distribute, sublicense, and/or sell copies
// of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
// BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
// ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once

#include <ableton/cassowary/Targeted.hpp>
#include <limits>

namespace ableton {
namespace cassowary {

class Edit : public Targeted
{
  Q_OBJECT

public:
  Edit(QQuickItem* pParent=0);

  Q_PROPERTY(double suggested
             MEMBER mSuggested NOTIFY suggestedChanged)
  Q_SIGNAL void suggestedChanged(double suggested);

  Q_INVOKABLE void suggest(double value);

protected:
  void addIn(Context& solver) override;
  void removeIn(Context& solver) override;

private:
  double mSuggested = std::numeric_limits<double>::quiet_NaN();
};

} // namespace cassowary
} // namespace ableton
