/* Copyright 2017 R. Thomas
 * Copyright 2017 Quarkslab
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <string>
#include <sstream>

#include "pyELF.hpp"

#include "LIEF/ELF/GnuHash.hpp"


template<class T>
using getter_t = T (GnuHash::*)(void) const;

template<class T>
using setter_t = void (GnuHash::*)(T);

void init_ELF_GnuHash_class(py::module& m) {

  py::class_<GnuHash>(m, "GnuHash")
    .def(py::init<>())

    .def_property_readonly("nb_buckets",
      &GnuHash::nb_buckets,
      "Return the number of buckets")

    .def_property_readonly("symbol_index",
      &GnuHash::symbol_index,
      "Index of the first symbol in the dynamic symbols table which accessible with the hash table")

    .def_property_readonly("shift2",
      &GnuHash::shift2,
      "Shift count used in the bloom filter")

    .def_property_readonly("bloom_filters",
      &GnuHash::bloom_filters,
      "Bloom filters",
      py::return_value_policy::reference_internal)

    .def_property_readonly("bloom_filters",
      &GnuHash::bloom_filters,
      "Bloom filters",
      py::return_value_policy::reference_internal)

    .def_property_readonly("buckets",
      &GnuHash::buckets,
      "hash buckets",
      py::return_value_policy::reference_internal)

    .def_property_readonly("hash_values",
      &GnuHash::hash_values,
      "Hash values",
      py::return_value_policy::reference_internal)

    .def("__str__",
        [] (const GnuHash& gnuhash)
        {
          std::ostringstream stream;
          stream << gnuhash;
          std::string str = stream.str();
          return str;
        });



}
