# Análise de Log de Servidor Web

## Contexto:
Uma empresa de tecnologia gerencia vários servidores web que geram grandes arquivos de log diariamente. Esses logs contêm informações importantes, como endereços IP dos usuários, datas de acesso, e status de resposta. A empresa deseja processar esses logs para gerar estatísticas diárias, como o número de acessos por hora e a quantidade de respostas bem-sucedidas.

## Tarefa:
Como analista de sistemas, você deve implementar uma solução em multithreading para processar os arquivos de log de forma eficiente. Cada thread deve ser responsável por processar uma parte diferente do log, computando estatísticas independentes sem a necessidade de sincronização complexa.

## Requisitos:

  - Baixe o arquivo de log disponível em <http://cti.videira.ifc.edu.br/~angelita/access.log>
  -  Divida o arquivo de log em várias partes e atribua uma thread para processar cada parte.
  - Cada thread deve calcular o número de acessos por hora e o número de respostas com código de status 200 (OK) em sua parte do log.
   - As threads não devem compartilhar dados entre si, eliminando a necessidade de semáforos ou outras formas de sincronização.
   - Após todas as threads concluírem o processamento, os resultados devem ser combinados para gerar estatísticas finais para o dia.

## Objetivo:

O objetivo é usar threads para acelerar o processamento dos arquivos de log, permitindo a análise rápida de grandes volumes de dados sem riscos de deadlocks ou a complexidade de gerenciar dados compartilhados.
