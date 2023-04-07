#include <stdio.h>

#include "version.h"

int main(void)
{
    printf("GIT_REV is %s\n", GIT_REV);
    printf("GIT_TAG is %s\n", GIT_TAG);
    printf("GIT_BRANCH is %s\n", GIT_BRANCH);

    return 0;
}
