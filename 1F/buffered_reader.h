class BufferedReader {
 public:
  explicit BufferedReader(PackageStream* stream) {

  }
  int32_t Read(char* output_buffer, int32_t buffer_len);
};