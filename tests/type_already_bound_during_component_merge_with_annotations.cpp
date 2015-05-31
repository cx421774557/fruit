// expect-compile-error DuplicateTypesInComponentError<fruit::Annotated<Annotation,int>>|The installed component provides some types that are already provided
/*
 * Copyright 2014 Google Inc. All rights reserved.
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

#include <fruit/fruit.h>

using fruit::Component;
using fruit::Injector;
using fruit::createComponent;

struct Annotation {};

using intAnnot = fruit::Annotated<Annotation, int>;

Component<intAnnot> getComponent() {
  return createComponent()
    .registerConstructor<intAnnot()>();
}

void f() {
  fruit::NormalizedComponent<intAnnot> nc(getComponent());
  fruit::Injector<intAnnot> injector(nc, getComponent());
}