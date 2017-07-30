/* Copyright (c) 2017 David Tardon <dtardon@redhat.com>
 * This file is a part of libeot, which is licensed under the MPL license, version 2.0.
 * For full details, see the file LICENSE
 */

#include <cstdint>

#include <libeot/libeot.h>

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
  EOTMetadata metadata;
  uint8_t *outBuf = 0;
  unsigned outSize = 0;
  EOT2ttf_buffer(data, unsigned(size), &metadata, &outBuf, &outSize);
  EOTfreeMetadata(&metadata);
  EOTfreeBuffer(outBuf);
  return 0;
}

/* vim:set shiftwidth=2 softtabstop=2 expandtab: */
