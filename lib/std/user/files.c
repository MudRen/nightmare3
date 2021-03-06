/*    /std/user/files.c
 *    from Nightmare IV
 *    returns all files matching a wildcard expression
 *    created by someone at Portals a long time ago
 */

#include <dirs.h>
#include "files.h"

string *wild_card(string str) {
    mixed pf;
    string *tmp;
    string cwd;
    int i, maxi;

    if((cwd = absolute_path(query_cwd(), str)) == "/") return ({ "/" });
    if((string)(pf = path_file(cwd)) == "/") pf[0] = "";
    if(!(tmp = get_dir(cwd))) tmp = ({});
    tmp -= ({ "." });
    tmp -= ({ ".." });
    if(!str || str[0] != '.')
      tmp = filter_array(tmp, "remove_dots", this_object());
    for(i=0, maxi = sizeof(tmp); i < maxi; i++) {
        if(file_size(sprintf("%s/%s", pf[0], pf[1])) == -2) tmp[i] = pf[0];
        else tmp[i] = sprintf("%s/%s", pf[0], tmp[i]);
        if(strlen(tmp[i]) > 1 && tmp[i][0..1] == "//")
          tmp[i] = tmp[i][1..strlen(tmp[i])-1];
    }
    return tmp;
}

nomask  protected  int remove_dots(string str) { return !(str[0] == '.'); }

string query_cwd() { return DIR_TMP; }
