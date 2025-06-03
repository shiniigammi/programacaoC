#include <gtk/gtk.h>

GtkWidget *label;
int etapa = 0;

void atualizar_pergunta() {
    switch (etapa) {
        case 0:
            gtk_label_set_text(GTK_LABEL(label), "A bagaça funciona?");
            break;
        case 1:
            gtk_label_set_text(GTK_LABEL(label), "Você que fodeu com o treco?");
            break;
        case 2:
            gtk_label_set_text(GTK_LABEL(label), "Alguém sabe que foi você?");
            break;
        case 3:
            gtk_label_set_text(GTK_LABEL(label), "Dá pra jogar a culpa em alguém?");
            break;
        case 4:
            gtk_label_set_text(GTK_LABEL(label), "Alguém pode te culpar?");
            break;
        case 100:
            gtk_label_set_text(GTK_LABEL(label), ">>> NEM MEXA. SEM PROBLEMAS.");
            break;
        case 200:
            gtk_label_set_text(GTK_LABEL(label), ">>> ESCONDA. SEM PROBLEMAS.");
            break;
        case 201:
            gtk_label_set_text(GTK_LABEL(label), ">>> SE FODEU.");
            break;
        case 202:
            gtk_label_set_text(GTK_LABEL(label), ">>> SEM PROBLEMAS.");
            break;
        case 203:
            gtk_label_set_text(GTK_LABEL(label), ">>> ENTAO FODA-SE. SEM PROBLEMAS.");
            break;
        case 204:
            gtk_label_set_text(GTK_LABEL(label), ">>> SE FODEU MESMO.");
            break;
    }
}

void on_sim_clicked(GtkButton *button, gpointer user_data) {
    if (etapa == 0) {
        etapa = 100; // Funciona -> Nem mexa
    } else if (etapa == 1) {
        etapa = 2; // Fodeu -> Pergunta se sabem
    } else if (etapa == 2) {
        etapa = 3; // Sabem -> Pergunta se dá pra culpar alguém
    } else if (etapa == 3) {
        etapa = 202; // Dá pra culpar -> Sem problemas
    } else if (etapa == 4) {
        etapa = 3; // Podem culpar -> Pergunta se dá pra culpar alguém
    }
    atualizar_pergunta();
}

void on_nao_clicked(GtkButton *button, gpointer user_data) {
    if (etapa == 0) {
        etapa = 1; // Não funciona -> Pergunta se foi você
    } else if (etapa == 1) {
        etapa = 4; // Não foi você -> Pergunta se podem te culpar
    } else if (etapa == 2) {
        etapa = 200; // Ninguém sabe -> Esconda
    } else if (etapa == 3) {
        etapa = 204; // Não dá pra culpar -> Se fodeu mesmo
    } else if (etapa == 4) {
        etapa = 203; // Ninguém pode culpar -> Então foda-se
    }
    atualizar_pergunta();
}

void on_reset_clicked(GtkButton *button, gpointer user_data) {
    etapa = 0;
    atualizar_pergunta();
}

int main(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *vbox;
    GtkWidget *hbox;
    GtkWidget *btn_sim, *btn_nao, *btn_reset;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Solucionador de Problemas");
    gtk_container_set_border_width(GTK_CONTAINER(window), 20);
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 200);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    vbox = gtk_vbox_new(FALSE, 10);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    label = gtk_label_new("A bagaça funciona?");
    gtk_box_pack_start(GTK_BOX(vbox), label, TRUE, TRUE, 10);

    hbox = gtk_hbox_new(TRUE, 10);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 10);

    btn_sim = gtk_button_new_with_label("Sim");
    g_signal_connect(btn_sim, "clicked", G_CALLBACK(on_sim_clicked), NULL);
    gtk_box_pack_start(GTK_BOX(hbox), btn_sim, TRUE, TRUE, 5);

    btn_nao = gtk_button_new_with_label("Não");
    g_signal_connect(btn_nao, "clicked", G_CALLBACK(on_nao_clicked), NULL);
    gtk_box_pack_start(GTK_BOX(hbox), btn_nao, TRUE, TRUE, 5);

    btn_reset = gtk_button_new_with_label("Reiniciar");
    g_signal_connect(btn_reset, "clicked", G_CALLBACK(on_reset_clicked), NULL);
    gtk_box_pack_start(GTK_BOX(vbox), btn_reset, TRUE, TRUE, 5);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}