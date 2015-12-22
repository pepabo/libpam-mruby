#include "mruby.h"

int pam_mruby_check(FILE *rbfile, const char *name, const char *passwd)
{
  mrb_value ret;

  mrb_state *mrb = mrb_open();
  mrb_load_file(mrb, rbfile);
  ret = mrb_funcall(mrb, mrb_top_self(mrb), "check", 2,
                    mrb_str_new_cstr(mrb, name),
                    mrb_str_new_cstr(mrb, passwd));
  mrb_close(mrb);

  if (mrb_type(ret) == MRB_TT_TRUE)
    return 1;
  else
    return 0;
}
