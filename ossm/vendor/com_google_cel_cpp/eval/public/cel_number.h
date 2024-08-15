// Copyright 2022 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef THIRD_PARTY_CEL_CPP_EVAL_PUBLIC_CEL_NUMERIC_H_
#define THIRD_PARTY_CEL_CPP_EVAL_PUBLIC_CEL_NUMERIC_H_

#include <cmath>
#include <cstdint>
#include <limits>

#include "absl/types/optional.h"
#include "eval/public/cel_value.h"
#include "internal/number.h"

namespace google::api::expr::runtime {

using CelNumber = cel::internal::Number;

// Return a CelNumber if the value holds a numeric type, otherwise return
// nullopt.
absl::optional<CelNumber> GetNumberFromCelValue(const CelValue& value);

}  // namespace google::api::expr::runtime

#endif  // THIRD_PARTY_CEL_CPP_EVAL_PUBLIC_CEL_NUMERIC_H_
