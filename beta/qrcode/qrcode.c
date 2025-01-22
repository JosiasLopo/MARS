#include <qrencode.h>
#include <stdio.h>
#include <stdlib.h>

fgets(novoEvento.oradores, MAX_TAMANHO_NOME, stdin);
novoEvento.oradores[strcspn(novoEvento.oradores, "\n")] = '\0';

// Função para gerar e imprimir o QR Code
void generate_qr_code(const char *string) {
  // Codifica a string em QR Code
  QRcode *code = QRcode_encodeString(string, 0, QR_ECLEVEL_L, QR_MODE_8, 1);

  if (code != NULL) {
    // Imprime o QR Code no terminal
    for (int y = 0; y < code->width; y++) {
      for (int x = 0; x < code->width; x++) {
        // Atribui um caractere para cada módulo do QR Code
        putchar(code->data[y * code->width + x] ? '#' : ' ');
      }
      putchar('\n');
    }

    // Libera a memória alocada pelo QRcode_encodeString
    QRcode_free(code);
  } else {
    fprintf(stderr, "Erro ao gerar QR Code.\n");
  }
}

int main() {
  // String que será convertida em QR Code
  const char *string = "Hello, QR Code!";

  // Chama a função para gerar o QR Code
  generate_qr_code(string);

  return 0;
}
