#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int a[4], b[4], result[4], expected[4], score = 0, level = 1;
    int subtract, choice, correct, i, carry;
    
    srand(time(NULL));
    printf("\n🔥 4-BIT ALU BATTLE - BITFORGE GAMING 🔥\n");
    
    while(1) {
        for(i = 0; i < 4; i++) {
            a[i] = rand() % 2; b[i] = rand() % 2; expected[i] = 0;
        }
        subtract = rand() % 2;
        
        printf("\n🏆 LEVEL %d | SCORE: %d\n", level, score);
        printf("A: "); for(i=3;i>=0;i--) printf("%d", a[i]);
        printf(" %c B: ", subtract ? '-' : '+'); for(i=3;i>=0;i--) printf("%d", b[i]);
        printf("\nEnter result bits: ");
        for(i=0; i<4; i++) scanf("%d", &result[i]);
        
        carry = subtract;
        for(i=0; i<4; i++) {
            int ai=a[i], bi=(b[i]^subtract), sum=ai^bi^carry;
            expected[i]=sum; carry=(ai&bi)|(ai&carry)|(bi&carry);
        }
        
        printf("You:   "); for(i=3;i>=0;i--) printf("%d", result[i]);
        printf("\nCorrect: "); for(i=3;i>=0;i--) printf("%d", expected[i]);
        
        correct=1; for(i=0;i<4;i++) if(result[i]!=expected[i]) correct=0;
        if(correct) { score+=10*level++; printf("\n✅ WIN! +%d pts", 10*(level-1)); }
        else printf("\n❌ FAIL! Try carry propagation");
        
        printf("\n[1=Next 0=Quit]: "); scanf("%d", &choice);
        if(!choice) break;
    }
    printf("\n🎮 GAME OVER | FINAL: %d\n", score);
}
