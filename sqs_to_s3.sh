#!/bin/bash

# Encerra o script em caso de erro
set -e

# Captura sinais de interrupção e remove o arquivo temporário
trap 'rm -f temp.txt; exit' INT TERM

# Define o URL da fila SQS
queue_url="https://sqs.us-east-1.amazonaws.com/123456789012/registros"

# Recebe e processa as mensagens da fila até que ela esteja vazia
while true; do
  # Recebe uma mensagem da fila SQS e armazena o corpo, o timestamp e o receipt handle da mensagem em variáveis
  response=$(aws sqs receive-message --queue-url $queue_url --max-number-of-messages 1 --message-attribute-names SentTimestamp --wait-time-seconds 20 --query 'Messages[0]')
  message=$(echo $response | jq -r '.Body')
  timestamp=$(echo $response | jq -r '.MessageAttributes.SentTimestamp.StringValue')
  receipt_handle=$(echo $response | jq -r '.ReceiptHandle')

  # Verifica se as variáveis message e timestamp não estão vazias
  if [ -n "$message" ] && [ -n "$timestamp" ]; then
    # Calcula a diferença entre a data atual e o timestamp da mensagem em segundos
    current_date=$(date +%s)
    difference=$((current_date - timestamp / 1000))
    # Verifica se a diferença é maior do que uma semana (604800 segundos)
    if [ $difference -gt 604800 ]; then
      # Cria um arquivo temporário com o conteúdo da mensagem
      echo "$message" > temp.txt
      # Copia o arquivo temporário para o bucket s3 registros3
      aws s3 cp temp.txt s3://registros3
      # Exclui a mensagem da fila SQS usando o receipt handle
      aws sqs delete-message --queue-url $queue_url --receipt-handle $receipt_handle
      # Imprime uma mensagem de sucesso
      echo "Dados salvos no bucket s3 registros3 e excluídos da fila SQS registros"
    else
      # Imprime uma mensagem de aviso
      echo "Mensagem ignorada por ser mais recente do que uma semana"
    fi
  else
    # Imprime uma mensagem de fim
    echo "Nenhuma mensagem restante na fila SQS registros"
    # Sai do loop
    break
  fi
done

# Remove o arquivo temporário
rm -f temp.txt
