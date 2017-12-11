#include <lh_parson.h>
#include <libhandler.h>


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

lh_value my_exn_handle(lh_value(*action)(value), lh_value arg) {
  return lh_handle(&_exn_def, lh_value_null, action, arg);
}
