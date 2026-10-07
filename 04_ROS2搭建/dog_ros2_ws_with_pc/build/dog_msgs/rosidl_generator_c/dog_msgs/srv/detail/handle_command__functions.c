// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from dog_msgs:srv/HandleCommand.idl
// generated code does not contain a copyright notice
#include "dog_msgs/srv/detail/handle_command__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
dog_msgs__srv__HandleCommand_Request__init(dog_msgs__srv__HandleCommand_Request * msg)
{
  if (!msg) {
    return false;
  }
  // command
  return true;
}

void
dog_msgs__srv__HandleCommand_Request__fini(dog_msgs__srv__HandleCommand_Request * msg)
{
  if (!msg) {
    return;
  }
  // command
}

bool
dog_msgs__srv__HandleCommand_Request__are_equal(const dog_msgs__srv__HandleCommand_Request * lhs, const dog_msgs__srv__HandleCommand_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // command
  if (lhs->command != rhs->command) {
    return false;
  }
  return true;
}

bool
dog_msgs__srv__HandleCommand_Request__copy(
  const dog_msgs__srv__HandleCommand_Request * input,
  dog_msgs__srv__HandleCommand_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // command
  output->command = input->command;
  return true;
}

dog_msgs__srv__HandleCommand_Request *
dog_msgs__srv__HandleCommand_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dog_msgs__srv__HandleCommand_Request * msg = (dog_msgs__srv__HandleCommand_Request *)allocator.allocate(sizeof(dog_msgs__srv__HandleCommand_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(dog_msgs__srv__HandleCommand_Request));
  bool success = dog_msgs__srv__HandleCommand_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
dog_msgs__srv__HandleCommand_Request__destroy(dog_msgs__srv__HandleCommand_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    dog_msgs__srv__HandleCommand_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
dog_msgs__srv__HandleCommand_Request__Sequence__init(dog_msgs__srv__HandleCommand_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dog_msgs__srv__HandleCommand_Request * data = NULL;

  if (size) {
    data = (dog_msgs__srv__HandleCommand_Request *)allocator.zero_allocate(size, sizeof(dog_msgs__srv__HandleCommand_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = dog_msgs__srv__HandleCommand_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        dog_msgs__srv__HandleCommand_Request__fini(&data[i - 1]);
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
dog_msgs__srv__HandleCommand_Request__Sequence__fini(dog_msgs__srv__HandleCommand_Request__Sequence * array)
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
      dog_msgs__srv__HandleCommand_Request__fini(&array->data[i]);
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

dog_msgs__srv__HandleCommand_Request__Sequence *
dog_msgs__srv__HandleCommand_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dog_msgs__srv__HandleCommand_Request__Sequence * array = (dog_msgs__srv__HandleCommand_Request__Sequence *)allocator.allocate(sizeof(dog_msgs__srv__HandleCommand_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = dog_msgs__srv__HandleCommand_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
dog_msgs__srv__HandleCommand_Request__Sequence__destroy(dog_msgs__srv__HandleCommand_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    dog_msgs__srv__HandleCommand_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
dog_msgs__srv__HandleCommand_Request__Sequence__are_equal(const dog_msgs__srv__HandleCommand_Request__Sequence * lhs, const dog_msgs__srv__HandleCommand_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!dog_msgs__srv__HandleCommand_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
dog_msgs__srv__HandleCommand_Request__Sequence__copy(
  const dog_msgs__srv__HandleCommand_Request__Sequence * input,
  dog_msgs__srv__HandleCommand_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(dog_msgs__srv__HandleCommand_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    dog_msgs__srv__HandleCommand_Request * data =
      (dog_msgs__srv__HandleCommand_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!dog_msgs__srv__HandleCommand_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          dog_msgs__srv__HandleCommand_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!dog_msgs__srv__HandleCommand_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
dog_msgs__srv__HandleCommand_Response__init(dog_msgs__srv__HandleCommand_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  return true;
}

void
dog_msgs__srv__HandleCommand_Response__fini(dog_msgs__srv__HandleCommand_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
}

bool
dog_msgs__srv__HandleCommand_Response__are_equal(const dog_msgs__srv__HandleCommand_Response * lhs, const dog_msgs__srv__HandleCommand_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  return true;
}

bool
dog_msgs__srv__HandleCommand_Response__copy(
  const dog_msgs__srv__HandleCommand_Response * input,
  dog_msgs__srv__HandleCommand_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  return true;
}

dog_msgs__srv__HandleCommand_Response *
dog_msgs__srv__HandleCommand_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dog_msgs__srv__HandleCommand_Response * msg = (dog_msgs__srv__HandleCommand_Response *)allocator.allocate(sizeof(dog_msgs__srv__HandleCommand_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(dog_msgs__srv__HandleCommand_Response));
  bool success = dog_msgs__srv__HandleCommand_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
dog_msgs__srv__HandleCommand_Response__destroy(dog_msgs__srv__HandleCommand_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    dog_msgs__srv__HandleCommand_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
dog_msgs__srv__HandleCommand_Response__Sequence__init(dog_msgs__srv__HandleCommand_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dog_msgs__srv__HandleCommand_Response * data = NULL;

  if (size) {
    data = (dog_msgs__srv__HandleCommand_Response *)allocator.zero_allocate(size, sizeof(dog_msgs__srv__HandleCommand_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = dog_msgs__srv__HandleCommand_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        dog_msgs__srv__HandleCommand_Response__fini(&data[i - 1]);
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
dog_msgs__srv__HandleCommand_Response__Sequence__fini(dog_msgs__srv__HandleCommand_Response__Sequence * array)
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
      dog_msgs__srv__HandleCommand_Response__fini(&array->data[i]);
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

dog_msgs__srv__HandleCommand_Response__Sequence *
dog_msgs__srv__HandleCommand_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dog_msgs__srv__HandleCommand_Response__Sequence * array = (dog_msgs__srv__HandleCommand_Response__Sequence *)allocator.allocate(sizeof(dog_msgs__srv__HandleCommand_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = dog_msgs__srv__HandleCommand_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
dog_msgs__srv__HandleCommand_Response__Sequence__destroy(dog_msgs__srv__HandleCommand_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    dog_msgs__srv__HandleCommand_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
dog_msgs__srv__HandleCommand_Response__Sequence__are_equal(const dog_msgs__srv__HandleCommand_Response__Sequence * lhs, const dog_msgs__srv__HandleCommand_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!dog_msgs__srv__HandleCommand_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
dog_msgs__srv__HandleCommand_Response__Sequence__copy(
  const dog_msgs__srv__HandleCommand_Response__Sequence * input,
  dog_msgs__srv__HandleCommand_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(dog_msgs__srv__HandleCommand_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    dog_msgs__srv__HandleCommand_Response * data =
      (dog_msgs__srv__HandleCommand_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!dog_msgs__srv__HandleCommand_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          dog_msgs__srv__HandleCommand_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!dog_msgs__srv__HandleCommand_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
