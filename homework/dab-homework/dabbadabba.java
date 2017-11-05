public class dabbadabba
{
    public static final int THREE_STEPS = 3;

    public static void drawLine() {
        for (int i = 0; i < (THREE_STEPS+1)*2+1; i++) {
            System.out.print("-");
        }
    }
    public static void drawWall() {
        drawLine();
        System.out.print("| %");
        for (int i = 0; i < 4; i++) {
            System.out.print(" ");
        }
        System.out.print("% |" );
        drawLine();
        System.out.println();
    }

    public static void drawWindows() {
        drawWall();
        for (int i = 0; i < THREE_STEPS+1; i++) {
            System.out.print(" o");
        }
        System.out.print(" | %");
        for (int i = 0; i < 4; i++) {
            System.out.print(" ");
        }
        System.out.print("% | ");
        for (int i = 0; i < THREE_STEPS+1; i++) {
            System.out.print("o ");
        }
        System.out.println();
        drawWall();
    }

    public static void drawSteps() {
        for (int i = 0; i < THREE_STEPS; i++) {
            for (int j = 0; j < (THREE_STEPS+1)-i; j++) {
                System.out.print("~^");
            }
            System.out.print("~/");
            for (int j = 0; j < 8+4*i; j++) {
                System.out.print("-");
            }
            System.out.print("\\~");
            for (int j = 0; j < (THREE_STEPS+1)-i; j++) {
                System.out.print("^~");
                }
                System.out.println();
                for (int j = 0; j < (THREE_STEPS+1)-i; j++) {
                    System.out.print("^~");
                    }
                    System.out.print("/");
                        for (int j = 0; j < 10+4*i; j++) {
                            System.out.print("-");
                        }
                        System.out.print("\\");
                            for (int j = 0; j < (THREE_STEPS+1)-i; j++) {
                            System.out.print("~^");
                            }
                            System.out.println();
                            for (int j = 0; j < (THREE_STEPS+1)*2-(2*i); j++) {
                            System.out.print(" ");
                            }
                    System.out.print("|");
                for (int j = 0; j < 10+4*i; j++) {
                            System.out.print("=");
                    }
            System.out.print("|");
            System.out.println();
        }
    }

    public static void main(String[] args) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < (THREE_STEPS+1)*2+(5-i); j++) {
                System.out.print(" ");
            }
            System.out.print("/");
            for (int j = 0; j < i; j++) {
                System.out.print("/\\");
            }
            System.out.println("\\");
        }
        drawWindows();
        drawSteps();
        System.out.print("   /");
        for (int i = 0; i < 12+4*(THREE_STEPS-1); i++){
                System.out.print(" ");
        }
        System.out.print("\\");
        System.out.println();
        System.out.print("  /  ");
        for (int i = 0; i < 10+4*(THREE_STEPS-1); i++){
                System.out.print("=");
        }
        System.out.print("  \\");
        System.out.println();
        System.out.print(" /  / ");
        for (int i = 0; i < 8+4*(THREE_STEPS-1); i++){
            System.out.print("\"");
        }
        System.out.print(" \\  \\");
        System.out.println();
        System.out.print("|  | ");
        for (int i = 0; i < 10+4*(THREE_STEPS-1); i++){
            System.out.print("\"");
        }
        System.out.print(" |  |");
        System.out.println();
        System.out.print(" \\  \\ ");
        for (int i = 0; i < 8+4*(THREE_STEPS-1); i++){
            System.out.print("\"");
        }
        System.out.print(" /  /");
        System.out.println();
        System.out.print("  \\  ");
        for (int i = 0; i < 10+4*(THREE_STEPS-1); i++) {
            System.out.print("=");
        }
        System.out.print("  /");
        System.out.println();
        System.out.print("   \\");
        for (int i = 0; i < 12+4*(THREE_STEPS-1); i++) {
            System.out.print("_");
        }
        System.out.println("/");
    }
}
