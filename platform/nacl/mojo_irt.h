// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MOJO_PUBLIC_PLATFORM_NACL_MOJO_IRT_H_
#define MOJO_PUBLIC_PLATFORM_NACL_MOJO_IRT_H_

#include <mojo/result.h>
#include <mojo/system/buffer.h>
#include <mojo/system/data_pipe.h>
#include <mojo/system/handle.h>
#include <mojo/system/message_pipe.h>
#include <mojo/system/time.h>
#include <mojo/system/wait_set.h>

#define NACL_IRT_MOJO_v0_1 "nacl-irt-mojo-0.1"

struct nacl_irt_mojo {
  MojoResult (*_MojoGetInitialHandle)(MojoHandle* handle);
  MojoTimeTicks (*MojoGetTimeTicksNow)();
  MojoResult (*MojoClose)(MojoHandle handle);
  MojoResult (*MojoGetRights)(MojoHandle handle, MojoHandleRights* rights);
  MojoResult (*MojoReplaceHandleWithReducedRights)(
      MojoHandle handle,
      MojoHandleRights rights_to_remove,
      MojoHandle* replacement_handle);
  MojoResult (*MojoDuplicateHandleWithReducedRights)(
      MojoHandle handle,
      MojoHandleRights rights_to_remove,
      MojoHandle* new_handle);
  MojoResult (*MojoDuplicateHandle)(MojoHandle handle, MojoHandle* new_handle);
  MojoResult (*MojoWait)(MojoHandle handle,
                         MojoHandleSignals signals,
                         MojoDeadline deadline,
                         struct MojoHandleSignalsState* signals_state);
  MojoResult (*MojoWaitMany)(const MojoHandle* handles,
                             const MojoHandleSignals* signals,
                             uint32_t num_handles,
                             MojoDeadline deadline,
                             uint32_t* result_index,
                             struct MojoHandleSignalsState* signals_states);
  MojoResult (*MojoCreateMessagePipe)(
      const struct MojoCreateMessagePipeOptions* options,
      MojoHandle* message_pipe_handle0,
      MojoHandle* message_pipe_handle1);
  MojoResult (*MojoWriteMessage)(MojoHandle message_pipe_handle,
                                 const void* bytes,
                                 uint32_t num_bytes,
                                 const MojoHandle* handles,
                                 uint32_t num_handles,
                                 MojoWriteMessageFlags flags);
  MojoResult (*MojoReadMessage)(MojoHandle message_pipe_handle,
                                void* bytes,
                                uint32_t* num_bytes,
                                MojoHandle* handles,
                                uint32_t* num_handles,
                                MojoReadMessageFlags flags);
  MojoResult (*MojoCreateDataPipe)(
      const struct MojoCreateDataPipeOptions* options,
      MojoHandle* data_pipe_producer_handle,
      MojoHandle* data_pipe_consumer_handle);
  MojoResult (*MojoSetDataPipeProducerOptions)(
      MojoHandle data_pipe_producer_handle,
      const struct MojoDataPipeProducerOptions* options);
  MojoResult (*MojoGetDataPipeProducerOptions)(
      MojoHandle data_pipe_producer_handle,
      struct MojoDataPipeProducerOptions* options,
      uint32_t options_num_bytes);
  MojoResult (*MojoWriteData)(MojoHandle data_pipe_producer_handle,
                              const void* elements,
                              uint32_t* num_bytes,
                              MojoWriteDataFlags flags);
  MojoResult (*MojoBeginWriteData)(MojoHandle data_pipe_producer_handle,
                                   void** buffer,
                                   uint32_t* buffer_num_bytes,
                                   MojoWriteDataFlags flags);
  MojoResult (*MojoEndWriteData)(MojoHandle data_pipe_producer_handle,
                                 uint32_t num_bytes_written);
  MojoResult (*MojoSetDataPipeConsumerOptions)(
      MojoHandle data_pipe_consumer_handle,
      const struct MojoDataPipeConsumerOptions* options);
  MojoResult (*MojoGetDataPipeConsumerOptions)(
      MojoHandle data_pipe_consumer_handle,
      struct MojoDataPipeConsumerOptions* options,
      uint32_t options_num_bytes);
  MojoResult (*MojoReadData)(MojoHandle data_pipe_consumer_handle,
                             void* elements,
                             uint32_t* num_bytes,
                             MojoReadDataFlags flags);
  MojoResult (*MojoBeginReadData)(MojoHandle data_pipe_consumer_handle,
                                  const void** buffer,
                                  uint32_t* buffer_num_bytes,
                                  MojoReadDataFlags flags);
  MojoResult (*MojoEndReadData)(MojoHandle data_pipe_consumer_handle,
                                uint32_t num_bytes_read);
  MojoResult (*MojoCreateSharedBuffer)(
      const struct MojoCreateSharedBufferOptions* options,
      uint64_t num_bytes,
      MojoHandle* shared_buffer_handle);
  MojoResult (*MojoDuplicateBufferHandle)(
      MojoHandle buffer_handle,
      const struct MojoDuplicateBufferHandleOptions* options,
      MojoHandle* new_buffer_handle);
  MojoResult (*MojoGetBufferInformation)(MojoHandle buffer_handle,
                                         struct MojoBufferInformation* info,
                                         uint32_t info_num_bytes);
  MojoResult (*MojoMapBuffer)(MojoHandle buffer_handle,
                              uint64_t offset,
                              uint64_t num_bytes,
                              void** buffer,
                              MojoMapBufferFlags flags);
  MojoResult (*MojoUnmapBuffer)(void* buffer);
  MojoResult (*MojoCreateWaitSet)(
      const struct MojoCreateWaitSetOptions* options,
      MojoHandle* handle);
  MojoResult (*MojoWaitSetAdd)(MojoHandle wait_set_handle,
                               MojoHandle handle,
                               MojoHandleSignals signals,
                               uint64_t cookie,
                               const struct MojoWaitSetAddOptions* options);
  MojoResult (*MojoWaitSetRemove)(MojoHandle wait_set_handle, uint64_t cookie);
  MojoResult (*MojoWaitSetWait)(MojoHandle wait_set_handle,
                                MojoDeadline deadline,
                                uint32_t* num_results,
                                struct MojoWaitSetResult* results,
                                uint32_t* max_results);
};

#endif  // MOJO_PUBLIC_PLATFORM_NACL_MOJO_IRT_H_
