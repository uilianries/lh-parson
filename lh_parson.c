#include <libhandler.h>
#include <parson.h>
#include <lh_parson.h>

JSON_Value * json_parse_file_exn(const char *filename)
{
  JSON_Value * value = json_parse_file(filename);
  if (value != NULL) {
    return value;
  }
  else {
    exn_raise("error parsing file");
  }
}

