#ifndef CERT_H_
#define CERT_H_
unsigned char example_crt_DER[] = {
  0x30, 0x82, 0x02, 0x18, 0x30, 0x82, 0x01, 0x81, 0x02, 0x01, 0x02, 0x30,
  0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x0b,
  0x05, 0x00, 0x30, 0x54, 0x31, 0x0b, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04,
  0x06, 0x13, 0x02, 0x44, 0x45, 0x31, 0x0b, 0x30, 0x09, 0x06, 0x03, 0x55,
  0x04, 0x08, 0x0c, 0x02, 0x42, 0x45, 0x31, 0x0f, 0x30, 0x0d, 0x06, 0x03,
  0x55, 0x04, 0x07, 0x0c, 0x06, 0x42, 0x65, 0x72, 0x6c, 0x69, 0x6e, 0x31,
  0x12, 0x30, 0x10, 0x06, 0x03, 0x55, 0x04, 0x0a, 0x0c, 0x09, 0x4d, 0x79,
  0x43, 0x6f, 0x6d, 0x70, 0x61, 0x6e, 0x79, 0x31, 0x13, 0x30, 0x11, 0x06,
  0x03, 0x55, 0x04, 0x03, 0x0c, 0x0a, 0x6d, 0x79, 0x63, 0x61, 0x2e, 0x6c,
  0x6f, 0x63, 0x61, 0x6c, 0x30, 0x1e, 0x17, 0x0d, 0x32, 0x30, 0x31, 0x32,
  0x31, 0x33, 0x31, 0x31, 0x30, 0x39, 0x35, 0x31, 0x5a, 0x17, 0x0d, 0x33,
  0x30, 0x31, 0x32, 0x31, 0x31, 0x31, 0x31, 0x30, 0x39, 0x35, 0x31, 0x5a,
  0x30, 0x55, 0x31, 0x0b, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13,
  0x02, 0x44, 0x45, 0x31, 0x0b, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x08,
  0x0c, 0x02, 0x42, 0x45, 0x31, 0x0f, 0x30, 0x0d, 0x06, 0x03, 0x55, 0x04,
  0x07, 0x0c, 0x06, 0x42, 0x65, 0x72, 0x6c, 0x69, 0x6e, 0x31, 0x12, 0x30,
  0x10, 0x06, 0x03, 0x55, 0x04, 0x0a, 0x0c, 0x09, 0x4d, 0x79, 0x43, 0x6f,
  0x6d, 0x70, 0x61, 0x6e, 0x79, 0x31, 0x14, 0x30, 0x12, 0x06, 0x03, 0x55,
  0x04, 0x03, 0x0c, 0x0b, 0x65, 0x73, 0x70, 0x33, 0x32, 0x2e, 0x6c, 0x6f,
  0x63, 0x61, 0x6c, 0x30, 0x81, 0x9f, 0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86,
  0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x01, 0x05, 0x00, 0x03, 0x81, 0x8d,
  0x00, 0x30, 0x81, 0x89, 0x02, 0x81, 0x81, 0x00, 0xcc, 0x8c, 0x1b, 0x9a,
  0x8a, 0x54, 0x4f, 0x8d, 0xda, 0x5c, 0x6a, 0xfc, 0xde, 0x66, 0x1c, 0x98,
  0xb4, 0x8e, 0x26, 0x83, 0x07, 0x8f, 0x6a, 0x49, 0xbc, 0x37, 0x89, 0x8c,
  0x6b, 0x54, 0x2a, 0x70, 0x67, 0x31, 0x27, 0x1e, 0xac, 0x3d, 0xa1, 0x2d,
  0xa3, 0x7f, 0x84, 0x5d, 0x2a, 0x88, 0x1b, 0x98, 0x30, 0xcb, 0xdc, 0xa8,
  0x84, 0xc1, 0x0e, 0x06, 0xfe, 0xf6, 0x38, 0x08, 0xc0, 0x28, 0x53, 0x81,
  0xb9, 0x18, 0xfd, 0x0d, 0x3c, 0xbf, 0x42, 0x76, 0x42, 0xa7, 0x61, 0x6f,
  0x12, 0xea, 0xd7, 0x87, 0xd4, 0xca, 0x62, 0x69, 0x6f, 0xc3, 0x07, 0x32,
  0x69, 0xc6, 0xbc, 0x02, 0xa4, 0x38, 0x78, 0x73, 0x40, 0xa6, 0xb8, 0x11,
  0x9f, 0x68, 0xdc, 0xb0, 0x7f, 0xae, 0x55, 0x72, 0xcb, 0x49, 0x23, 0x34,
  0x26, 0xc6, 0x80, 0xeb, 0xf3, 0x01, 0x38, 0xaf, 0x1e, 0x4c, 0x6e, 0x80,
  0xcf, 0x03, 0x80, 0xdf, 0x02, 0x03, 0x01, 0x00, 0x01, 0x30, 0x0d, 0x06,
  0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x0b, 0x05, 0x00,
  0x03, 0x81, 0x81, 0x00, 0x25, 0x90, 0x17, 0xa1, 0xc9, 0x0b, 0x21, 0x49,
  0x7d, 0xf4, 0xef, 0xe3, 0x30, 0x53, 0xb6, 0xbb, 0x21, 0xb5, 0xdb, 0x31,
  0x37, 0x59, 0xb0, 0x24, 0x29, 0xdc, 0x95, 0x93, 0x17, 0x75, 0xd7, 0x24,
  0x5e, 0x47, 0x07, 0x34, 0xd2, 0x38, 0xed, 0x70, 0xa1, 0x9c, 0xac, 0x55,
  0xcc, 0xcc, 0x92, 0xaf, 0x32, 0x2d, 0x4b, 0xee, 0x7c, 0xf5, 0x0b, 0x1b,
  0xcd, 0x54, 0xc2, 0xf7, 0x6a, 0xe1, 0x49, 0x91, 0xec, 0xb8, 0x0e, 0x63,
  0xe2, 0xc1, 0x30, 0x9c, 0xc2, 0xfb, 0x9c, 0xc1, 0x63, 0x1e, 0x18, 0x52,
  0xaf, 0xae, 0x1e, 0x36, 0xd0, 0x2a, 0xf5, 0x66, 0xc7, 0x82, 0x97, 0xae,
  0x2a, 0xe2, 0x56, 0xfe, 0xa6, 0xc0, 0x59, 0x82, 0x4b, 0x60, 0x04, 0x4d,
  0x7a, 0xd1, 0xb0, 0xf5, 0x01, 0xc7, 0x7d, 0x4c, 0x45, 0x56, 0x6e, 0xdd,
  0xf5, 0x9e, 0x0f, 0x73, 0x92, 0x76, 0xfd, 0xcd, 0x1d, 0x83, 0xd8, 0x98
};
unsigned int example_crt_DER_len = 540;
#endif
