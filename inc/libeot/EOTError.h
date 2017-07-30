/* Copyright (c) 2013 Brennan T. Vincent <brennanv@email.arizona.edu>
 * This file is a part of libeot, which is licensed under the MPL license, version 2.0.
 * For full details, see the file LICENSE
 */

#ifndef __LIBEOT_EOTERROR_H__
#define __LIBEOT_EOTERROR_H__

#ifdef __cplusplus
extern "C" {
#endif

#define EOT_WARN 1000
enum EOTError
{
  EOT_SUCCESS,
  EOT_INSUFFICIENT_BYTES,
  EOT_HEADER_TOO_BIG,
  EOT_BOGUS_STRING_SIZE,
  EOT_CORRUPT_FILE,
  EOT_SECOND_STREAM_INCOMPLETE,
  EOT_THIRD_STREAM_INCOMPLETE,
  EOT_CANT_ALLOCATE_MEMORY,
  EOT_OTHER_STDLIB_ERROR,
  EOT_FWRITE_ERROR,
  EOT_COMPRESSION_NOT_YET_IMPLEMENTED,
  EOT_LOGIC_ERROR,
  EOT_NO_GLYF_TABLE,
  EOT_NO_MAXP_TABLE,
  EOT_NO_HEAD_TABLE,
  EOT_NO_HMTX_TABLE,
  EOT_NO_HDMX_TABLE,
  EOT_CORRUPT_HOPCODE_DATA,
  EOT_UNKNOWN_BUFFER_WRITE_ERROR,
  EOT_MTX_ERROR,
  EOT_MALFORMED_HEAD_TABLE,
  EOT_WARN_NOT_ENOUGH_SPACE_RESERVED = EOT_WARN,
  EOT_WARN_BAD_VERSION,
  EOT_WARN_NOT_ENOUGH_GLYPHS
};

#ifdef __cplusplus
}
#endif

#endif /* #define __LIBEOT_EOTERROR_H__ */

/* vim:set shiftwidth=2 softtabstop=2 expandtab: */
