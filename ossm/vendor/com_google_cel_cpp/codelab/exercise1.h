// Copyright 2021 Google LLC
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

#ifndef THIRD_PARTY_CEL_CPP_CODELAB_EXERCISE1_H_
#define THIRD_PARTY_CEL_CPP_CODELAB_EXERCISE1_H_

#include <string>

#include "absl/status/statusor.h"
#include "absl/strings/string_view.h"

namespace google::api::expr::codelab {

// Parse a cel expression and evaluate it. This assumes no special setup for
// the evaluation environment, and that the expression results in a string
// value.
absl::StatusOr<std::string> ParseAndEvaluate(absl::string_view cel_expr);

}  // namespace google::api::expr::codelab

#endif  // THIRD_PARTY_CEL_CPP_CODELAB_EXERCISE1_H_
