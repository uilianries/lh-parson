#include <libhandler.h>
#include <parson.h>
#include <lh_parson.h>

LH_DEFINE_EFFECT1(exn, raise)
LH_DEFINE_VOIDOP1(exn, raise, lh_string)

typedef const char* lh_JSON_Value;

#define lh_JSON_Value_value(v) ((JSON_Value)(v))
#define lh_value_JSON_Value(i) (lh_value(i))

lh_value handle_exn_raise(lh_resume* r, lh_value local, lh_value arg) {
  printf("exception raised: %s\n", lh_lh_string_value(arg));
  return lh_value_null;
}

const lh_operation _exn_ops[] = {
  {
    LH_OP_NORESUME, LH_OPTAG(exn,raise), &handle_exn_raise
  }
};

const lh_handlerdef _exn_def = {
  LH_EFFECT(exn), NULL, NULL, NULL, _exn_ops
};

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

