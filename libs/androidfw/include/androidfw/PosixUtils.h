/*
 * Copyright (C) 2018 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <memory>
#include <string>
#include <vector>

namespace android {
namespace util {

struct ProcResult {
  int status;
  std::string stdout_str;
  std::string stderr_str;

  explicit ProcResult(int status) : status(status) {}
  ProcResult(ProcResult&&) noexcept = default;
  ProcResult& operator=(ProcResult&&) noexcept = default;

  explicit operator bool() const { return status >= 0; }
};

// Fork, exec and wait for an external process. Returns status < 0 if the process could not be
// launched, otherwise a ProcResult containing the external process' exit status and captured
// stdout and stderr.
ProcResult ExecuteBinary(const std::vector<std::string>& argv);

} // namespace util
} // namespace android
