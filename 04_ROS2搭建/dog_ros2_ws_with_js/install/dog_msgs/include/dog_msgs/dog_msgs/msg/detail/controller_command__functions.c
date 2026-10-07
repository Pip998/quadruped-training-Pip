// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from dog_msgs:msg/ControllerCommand.idl
// generated code does not contain a copyright notice
#include "dog_msgs/msg/detail/controller_command__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
dog_msgs__msg__ControllerCommand__init(dog_msgs__msg__ControllerCommand * msg)
{
  if (!msg) {
    return false;
  }
  // kp
  // kd
  // q
  // w
  // tau
  return true;
}

void
dog_msgs__msg__ControllerCommand__fini(dog_msgs__msg__ControllerCommand * msg)
{
  if (!msg) {
    return;
  }
  // kp
  // kd
  // q
  // w
  // tau
}

bool
dog_msgs__msg__ControllerCommand__are_equal(const dog_msgs__msg__ControllerCommand * lhs, const dog_msgs__msg__ControllerCommand * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // kp
  for (size_t i = 0; i < 12; ++i) {
    if (lhs->kp[i] != rhs->kp[i]) {
      return false;
    }
  }
  // kd
  for (size_t i = 0; i < 12; ++i) {
    if (lhs->kd[i] != rhs->kd[i]) {
      return false;
    }
  }
  // q
  for (size_t i = 0; i < 12; ++i) {
    if (lhs->q[i] != rhs->q[i]) {
      return false;
    }
  }
  // w
  for (size_t i = 0; i < 12; ++i) {
    if (lhs->w[i] != rhs->w[i]) {
      return false;
    }
  }
  // tau
  for (size_t i = 0; i < 12; ++i) {
    if (lhs->tau[i] != rhs->tau[i]) {
      return false;
    }
  }
  return true;
}

bool
dog_msgs__msg__ControllerCommand__copy(
  const dog_msgs__msg__ControllerCommand * input,
  dog_msgs__msg__ControllerCommand * output)
{
  if (!input || !output) {
    return false;
  }
  // kp
  for (size_t i = 0; i < 12; ++i) {
    output->kp[i] = input->kp[i];
  }
  // kd
  for (size_t i = 0; i < 12; ++i) {
    output->kd[i] = input->kd[i];
  }
  // q
  for (size_t i = 0; i < 12; ++i) {
    output->q[i] = input->q[i];
  }
  // w
  for (size_t i = 0; i < 12; ++i) {
    output->w[i] = input->w[i];
  }
  // tau
  for (size_t i = 0; i < 12; ++i) {
    output->tau[i] = input->tau[i];
  }
  return true;
}

dog_msgs__msg__ControllerCommand *
dog_msgs__msg__ControllerCommand__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dog_msgs__msg__ControllerCommand * msg = (dog_msgs__msg__ControllerCommand *)allocator.allocate(sizeof(dog_msgs__msg__ControllerCommand), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(dog_msgs__msg__ControllerCommand));
  bool success = dog_msgs__msg__ControllerCommand__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
dog_msgs__msg__ControllerCommand__destroy(dog_msgs__msg__ControllerCommand * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    dog_msgs__msg__ControllerCommand__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
dog_msgs__msg__ControllerCommand__Sequence__init(dog_msgs__msg__ControllerCommand__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dog_msgs__msg__ControllerCommand * data = NULL;

  if (size) {
    data = (dog_msgs__msg__ControllerCommand *)allocator.zero_allocate(size, sizeof(dog_msgs__msg__ControllerCommand), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = dog_msgs__msg__ControllerCommand__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        dog_msgs__msg__ControllerCommand__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
dog_msgs__msg__ControllerCommand__Sequence__fini(dog_msgs__msg__ControllerCommand__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      dog_msgs__msg__ControllerCommand__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

dog_msgs__msg__ControllerCommand__Sequence *
dog_msgs__msg__ControllerCommand__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dog_msgs__msg__ControllerCommand__Sequence * array = (dog_msgs__msg__ControllerCommand__Sequence *)allocator.allocate(sizeof(dog_msgs__msg__ControllerCommand__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = dog_msgs__msg__ControllerCommand__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
dog_msgs__msg__ControllerCommand__Sequence__destroy(dog_msgs__msg__ControllerCommand__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    dog_msgs__msg__ControllerCommand__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
dog_msgs__msg__ControllerCommand__Sequence__are_equal(const dog_msgs__msg__ControllerCommand__Sequence * lhs, const dog_msgs__msg__ControllerCommand__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!dog_msgs__msg__ControllerCommand__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
dog_msgs__msg__ControllerCommand__Sequence__copy(
  const dog_msgs__msg__ControllerCommand__Sequence * input,
  dog_msgs__msg__ControllerCommand__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(dog_msgs__msg__ControllerCommand);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    dog_msgs__msg__ControllerCommand * data =
      (dog_msgs__msg__ControllerCommand *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!dog_msgs__msg__ControllerCommand__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          dog_msgs__msg__ControllerCommand__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!dog_msgs__msg__ControllerCommand__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
