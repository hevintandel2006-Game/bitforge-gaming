#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int a[4], b[4], result[4], expected[4], score = 0, level = 1;
    int subtract, choice, correct, i, carry;
    
    srand(time(NULL));
    printf("\n🔥 4-BIT ALU BATTLE - BITFORGE GAMING 🔥\n");
    printf("========================================\n");
    
    while(1) {
        // NEW: Generate random 4-bit numbers
        for(i = 0; i < 4; i++) {
            a[i] = rand() % 2; 
            b[i] = rand() % 2; 
            expected[i] = 0;
        }
        subtract = rand() % 2;
        
        // SHOW CHALLENGE (DECIMAL + BINARY)
        printf("\n🏆 LEVEL %d | SCORE: %d\n", level, score);
        int decA = 0, decB = 0;
        for(i=0; i<4; i++) decA |= a[i]<<i, decB |= b[i]<<i;
        
        printf("Challenge: %d (%d%d%d%d) %c %d (%d%d%d%d)\n", 
               decA, a[3],a[2],a[1],a[0], subtract?'-':'+', 
               decB, b[3],b[2],b[1],b[0]);
        
        printf("Enter result (4 bits): ");
        for(i=0; i<4; i++) scanf("%d", &result[i]);
        
        // REAL 4-BIT ALU LOGIC (UNCHANGED - YOUR CODE IS PERFECT!)
        carry = subtract;
        for(i=0; i<4; i++) {
            int ai=a[i], bi=(b[i]^subtract), sum=ai^bi^carry;
            expected[i]=sum; 
            carry=(ai&bi)|(ai&carry)|(bi&carry);
        }
        
        // BETTER OUTPUT
        printf("\nYour answer:   %d%d%d%d\n", result[3],result[2],result[1],result[0]);
        printf("Correct:       %d%d%d%d\n", expected[3],expected[2],expected[1],expected[0]);
        
        // CHECK (YOUR LOGIC PERFECT)
        correct=1; 
        for(i=0;i<4;i++) if(result[i]!=expected[i]) correct=0;
        
        if(correct) { 
            score+=10*level; 
            level++; 
            printf("\n✅ WIN! +%d pts | RISC:5 instr CISC:1 instr\n", 10*(level-1)); 
        }
        else printf("\n❌ FAIL! Check carry propagation\n");
        
        printf("\n[1=Next 0=Quit]: "); 
        scanf("%d", &choice);
        if(!choice) break;
    }
    printf("\n🎮 GAME OVER | FINAL SCORE: %d 🏆\n", score);
    return 0;
}

