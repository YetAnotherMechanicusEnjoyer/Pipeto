#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

uint32_t FUNC_0040b44f() {
    return 0;
}

uint32_t FUNC_0040b430() {
    return 0;
}

void processEntry(uint64_t param_1) {
    uint64_t *plVar11;
    uint64_t *plVar15;
    int iVar5;
    uint64_t lVar10;
    uint32_t uVar2, uVar3, uVar6;
    uint64_t uVar8;
    uint8_t bVar16, bVar17, bVar18;
    uint8_t *puVar12, *puVar13, *puVar14;
    uint64_t *puVar1;
    uint32_t extraout_EDX;
    uint64_t uVar4;
    uint64_t uVar7;
    uint64_t local_8 = 0;
    uint64_t local_18 = 0;
    uint64_t local_20 = 0;
    uint64_t local_cc0[399];

    plVar11 = (uint64_t *)&local_8;
    while (*plVar11 != 0) {
        plVar15 = plVar11 + 1;
        plVar11 = plVar11 + 1;
    }

    uVar8 = 0x1000;
    while (1) {
        puVar1 = (uint64_t *)(plVar11 + 1);
        lVar10 = *plVar11;
        if (lVar10 == 0) break;

        if ((int)lVar10 == 6) {
            uVar8 = *puVar1 & 0xffffffff;
            break;
        }
        plVar11 = plVar11 + 2;
    }

    local_8 = -uVar8;
    syscall();

    uVar4 = 0x13f;
    puVar12 = (uint8_t *)0x00409000;
    puVar13 = puVar12;
    plVar11 = local_cc0;
    uVar7 = 0;
    bVar16 = 0;
    bVar18 = 0;

    do {
        while (FUNC_0040b44f()) {
            *(uint8_t *)plVar11 = *puVar12;
            puVar12 += (bVar18 ? -2 : 1);
            plVar11 = (uint64_t *)((long)plVar11 + (bVar18 ? -2 : 1));
        }

        do {
            uVar3 = FUNC_0040b44f();
            bVar16 = (uVar3 != 0);
            uVar3 = FUNC_0040b44f();
            uVar6 = (uint32_t)uVar7;
        } while (bVar16);

        bVar16 = uVar3 < 3;
        if (!bVar16) {
            puVar13 += (bVar18 ? -2 : 1);
            bVar16 = false;
            uVar3 = (uVar3 - 3) ^ 0xffffffff;

            if (uVar3 == 0) {
                if (puVar13 == (uint8_t *)0x0040bdd2) {
                    local_cc0[0] = local_8;
                    lVar10 = local_18 - 0x10;
                    while (FUNC_0040b430());
                    lVar10 = FUNC_0040b430();
                    syscall();
                    FUNC_0040b44f();
                    return;
                }

                while (1);
            }
            lVar10 = (long)(int)uVar3;
        }

        FUNC_0040b44f();
        bVar17 = (uVar6 != 0);

        iVar5 = uVar6 * 2 + (uint)bVar16;
        if (uVar6 == 0) {
            uVar8 = uVar8 & 0xffffffff;
            bVar16 = (0xfffffffd < uVar3);
            do {
                uVar6 = (uint)uVar8;
                FUNC_0040b44f();
                uVar3 = (uint)bVar16;
                bVar16 = (uVar6 != 0);
                uVar8 = (uint64_t)(uVar6 * 2 + uVar3);
            } while (bVar16);
        }

        uVar2 = (uint32_t)((long)lVar10 < 0xfffff300);
        bVar16 = (uVar6 != 0);
        puVar14 = (uint8_t *)((long)plVar11 + lVar10);

        for (uVar8 = (uint64_t)(uVar6 + uVar3 + uVar2); uVar8 != 0; uVar8--) {
            *(uint8_t *)plVar11 = *puVar14;
            puVar14 += (bVar18 ? -2 : 1);
            plVar11 = (uint64_t *)((long)plVar11 + (bVar18 ? -2 : 1));
        }

        uVar7 = 0;
        puVar12 = puVar13;
    } while (1);
}
