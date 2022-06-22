#I create this "game" by my friends order. In a future I will redo the program code to make the game better and more algorithmic.

import pygame

pygame.init()

screen = pygame.display.set_mode((1500, 800))

pygame.display.set_caption("Интересные факты о ГМО")
pygame.display.set_icon(pygame.image.load("Directory/Icon/dna.png"))
bg = pygame.image.load("Directory/background/background.jpg")

bt = pygame.image.load("Directory/buttons/button1.png")
bt1 = pygame.image.load("Directory/buttons/button2.png")
bt2 = pygame.image.load("Directory/buttons/button3.png")
bt3 = pygame.image.load("Directory/buttons/button4.png")
bt4 = pygame.image.load("Directory/buttons/button5.png")
leave = pygame.image.load("Directory/buttons/leave.png")

button_start = pygame.image.load("Directory/buttons/button_start.png")
button_leave = pygame.image.load("Directory/buttons/button_leave.png")

main_window = True

x = 900
y = 20

info = pygame.image.load("Directory/information/info.png")
info1 = pygame.image.load("Directory/information/info1.png")
info2 = pygame.image.load("Directory/information/info2.png")
info3 = pygame.image.load("Directory/information/info3.png")
info4 = pygame.image.load("Directory/information/info4.png")

main_mind = pygame.image.load("Directory/mind/main_mind.png")
mind = pygame.image.load("Directory/mind/mind.png")
dna3 = pygame.image.load("Directory/mr_dna/dna.png")
dna1 = pygame.image.load("Directory/mr_dna/dna1.png")
dna2 = pygame.image.load("Directory/mr_dna/dna2.png")
dna = [dna1, dna2]
dna_pos = False
game = True

lv = False

but1 = False
but2 = False
but3 = False
but4 = False
but5 = False

while game:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            game = False
        key = pygame.key.get_pressed()
        pos = pygame.mouse.get_pos()
        click = pygame.mouse.get_pressed()

        if main_window and click[0] == 1 and pos[0] > 450 and pos[0] < 901 and pos[1] > 200 and pos[1] < 310:
            main_window = False
            dna_pos = True
        if  main_window and click[0] == 1 and pos[0] > 450 and pos[0] < 901 and pos[1] > 440 and pos[1] < 551:
            game = False


        if click[0] == 1 and pos[0] > 900 and pos[0] < 1451 and pos[1] > 20 and pos[1] < 160 and dna_pos:
            dna_pos = False
            but1 = True
            lv = True
        if click[0] == 1 and pos[0] > 900 and pos[0] < 1451 and pos[1] > 180 and pos[1] < 320 and dna_pos:
            dna_pos = False
            but2 = True
            lv = True
        if click[0] == 1 and pos[0] > 900 and pos[0] < 1451 and pos[1] > 340 and pos[1] < 480 and dna_pos:
            dna_pos = False
            but3 = True
            lv = True
        if click[0] == 1 and pos[0] > 900 and pos[0] < 1451 and pos[1] > 500 and pos[1] < 640 and dna_pos:
            dna_pos = False
            but4 = True
            lv = True
        if click[0] == 1 and pos[0] > 900 and pos[0] < 1451 and pos[1] > 660 and pos[1] < 800 and dna_pos:
            dna_pos = False
            but5 = True
            lv = True
        if dna_pos == False and click[0] == 1 and pos[0]>15 and pos[0] < 75 and pos[1] > 15 and pos[1] < 75 or key[pygame.K_q]:
            dna_pos = True
            but1 = False
            but2 = False
            but3 = False
            but4 = False
            but5 = False
            lv = False



    screen.blit(bg, (0, 0))


    if main_window:
        screen.blit(dna3, (20, 300))
        screen.blit(button_start, (450, 200))
        screen.blit(button_leave, (450, 440))
        screen.blit(mind, (150, 0))

    if dna_pos == True:
        screen.blit(dna[0],(-30, 400))
        screen.blit(main_mind, (120, 70))
        screen.blit(bt, (x, y))
        screen.blit(bt1, (x, y + 160))
        screen.blit(bt2, (x, y + 320))
        screen.blit(bt3, (x, y + 480))
        screen.blit(bt4, (x, y + 640))
    if but1 == True:
        screen.blit(dna[1], (-120, 400))
        screen.blit(leave, (15, 15))
        screen.blit(info, (450, 50))
    if but2 == True:
        screen.blit(dna[1], (-120, 400))
        screen.blit(leave, (15, 15))
        screen.blit(info1, (450, 50))
    if but3 == True:
        screen.blit(dna[1], (-120, 400))
        screen.blit(leave, (15, 15))
        screen.blit(info2, (450, 50))
    if but4 == True:
        screen.blit(dna[1], (-120, 400))
        screen.blit(leave, (15, 15))
        screen.blit(info3, (450, 50))
    if but5 == True:
        screen.blit(dna[1], (-120, 400))
        screen.blit(leave, (15, 15))
        screen.blit(info4, (450, 50))

    pygame.display.update()
