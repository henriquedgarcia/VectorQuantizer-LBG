TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cc \
    vectorquantizer.cc \
    main.cc \
    vectorquantizer.cc \
    main.cc \
    vectorquantizer.cc

DISTFILES += \
    README.md \
    treinamento1.tiff \
    treinamento2.tiff \
    treinamento3.tiff \
    treinamento4.tiff \
    codebooks/codebook-1x2-112.cdbk \
    codebooks/codebook-1x2-128.cdbk \
    codebooks/codebook-1x2-144.cdbk \
    codebooks/codebook-1x2-16.cdbk \
    codebooks/codebook-1x2-160.cdbk \
    codebooks/codebook-1x2-176.cdbk \
    codebooks/codebook-1x2-192.cdbk \
    codebooks/codebook-1x2-208.cdbk \
    codebooks/codebook-1x2-224.cdbk \
    codebooks/codebook-1x2-240.cdbk \
    codebooks/codebook-1x2-256.cdbk \
    codebooks/codebook-1x2-272.cdbk \
    codebooks/codebook-1x2-288.cdbk \
    codebooks/codebook-1x2-304.cdbk \
    codebooks/codebook-1x2-32.cdbk \
    codebooks/codebook-1x2-320.cdbk \
    codebooks/codebook-1x2-336.cdbk \
    codebooks/codebook-1x2-48.cdbk \
    codebooks/codebook-1x2-64.cdbk \
    codebooks/codebook-1x2-80.cdbk \
    codebooks/codebook-1x2-96.cdbk \
    codebooks/codebook-2x2-112.cdbk \
    codebooks/codebook-2x2-128.cdbk \
    codebooks/codebook-2x2-144.cdbk \
    codebooks/codebook-2x2-16.cdbk \
    codebooks/codebook-2x2-160.cdbk \
    codebooks/codebook-2x2-176.cdbk \
    codebooks/codebook-2x2-192.cdbk \
    codebooks/codebook-2x2-208.cdbk \
    codebooks/codebook-2x2-224.cdbk \
    codebooks/codebook-2x2-256.cdbk \
    codebooks/codebook-2x2-272.cdbk \
    codebooks/codebook-2x2-288.cdbk \
    codebooks/codebook-2x2-304.cdbk \
    codebooks/codebook-2x2-32.cdbk \
    codebooks/codebook-2x2-320.cdbk \
    codebooks/codebook-2x2-336.cdbk \
    codebooks/codebook-2x2-48.cdbk \
    codebooks/codebook-2x2-64.cdbk \
    codebooks/codebook-2x2-80.cdbk \
    codebooks/codebook-2x2-96.cdbk \
    codebooks/codebook-2x4-112.cdbk \
    codebooks/codebook-2x4-144.cdbk \
    codebooks/codebook-2x4-16.cdbk \
    codebooks/codebook-2x4-160.cdbk \
    codebooks/codebook-2x4-176.cdbk \
    codebooks/codebook-2x4-192.cdbk \
    codebooks/codebook-2x4-208.cdbk \
    codebooks/codebook-2x4-224.cdbk \
    codebooks/codebook-2x4-240.cdbk \
    codebooks/codebook-2x4-256.cdbk \
    codebooks/codebook-2x4-272.cdbk \
    codebooks/codebook-2x4-288.cdbk \
    codebooks/codebook-2x4-304.cdbk \
    codebooks/codebook-2x4-32.cdbk \
    codebooks/codebook-2x4-320.cdbk \
    codebooks/codebook-2x4-336.cdbk \
    codebooks/codebook-2x4-48.cdbk \
    codebooks/codebook-2x4-64.cdbk \
    codebooks/codebook-2x4-80.cdbk \
    codebooks/codebook-2x4-96.cdbk \
    codebooks/codebook-4x2-16.cdbk \
    codebooks/codebook-4x2-176.cdbk \
    codebooks/codebook-4x2-320.cdbk \
    codebooks/codebook-4x2-336.cdbk \
    codebooks/codebook-4x2-48.cdbk \
    codebooks/codebook-4x2-64.cdbk \
    codebooks/codebook-4x4-16.cdbk \
    codebooks/codebook-4x4-176.cdbk \
    codebooks/codebook-4x4-192.cdbk \
    codebooks/codebook-4x4-208.cdbk \
    codebooks/codebook-4x4-224.cdbk \
    codebooks/codebook-4x4-272.cdbk \
    codebooks/codebook-4x4-288.cdbk \
    codebooks/codebook-4x4-304.cdbk \
    codebooks/codebook-4x4-320.cdbk \
    quantizado/imagem-1x2-112.vci \
    quantizado/imagem-1x2-128.vci \
    quantizado/imagem-1x2-144.vci \
    quantizado/imagem-1x2-16.vci \
    quantizado/imagem-1x2-192.vci \
    quantizado/imagem-1x2-208.vci \
    quantizado/imagem-1x2-224.vci \
    quantizado/imagem-1x2-240.vci \
    quantizado/imagem-1x2-256.vci \
    quantizado/imagem-1x2-272.vci \
    quantizado/imagem-1x2-288.vci \
    quantizado/imagem-1x2-304.vci \
    quantizado/imagem-1x2-32.vci \
    quantizado/imagem-1x2-320.vci \
    quantizado/imagem-1x2-336.vci \
    quantizado/imagem-1x2-48.vci \
    quantizado/imagem-1x2-64.vci \
    quantizado/imagem-1x2-80.vci \
    quantizado/imagem-2x2-16.vci \
    quantizado/imagem-2x2-160.vci \
    quantizado/imagem-2x2-176.vci \
    quantizado/imagem-2x2-192.vci \
    quantizado/imagem-2x2-208.vci \
    quantizado/imagem-2x2-224.vci \
    quantizado/imagem-2x2-272.vci \
    quantizado/imagem-2x2-288.vci \
    quantizado/imagem-2x2-304.vci \
    quantizado/imagem-2x2-32.vci \
    quantizado/imagem-2x2-320.vci \
    quantizado/imagem-2x2-336.vci \
    quantizado/imagem-2x2-48.vci \
    quantizado/imagem-2x2-64.vci \
    quantizado/imagem-2x2-80.vci \
    quantizado/imagem-2x4-112.vci \
    quantizado/imagem-2x4-128.vci \
    quantizado/imagem-2x4-144.vci \
    quantizado/imagem-2x4-16.vci \
    quantizado/imagem-2x4-160.vci \
    quantizado/imagem-2x4-176.vci \
    quantizado/imagem-2x4-192.vci \
    quantizado/imagem-2x4-208.vci \
    quantizado/imagem-2x4-224.vci \
    quantizado/imagem-2x4-240.vci \
    quantizado/imagem-2x4-256.vci \
    quantizado/imagem-2x4-272.vci \
    quantizado/imagem-2x4-288.vci \
    quantizado/imagem-2x4-304.vci \
    quantizado/imagem-2x4-32.vci \
    quantizado/imagem-2x4-320.vci \
    quantizado/imagem-2x4-336.vci \
    quantizado/imagem-2x4-48.vci \
    quantizado/imagem-2x4-64.vci \
    quantizado/imagem-2x4-80.vci \
    quantizado/imagem-2x4-96.vci \
    quantizado/imagem-4x2-112.vci \
    quantizado/imagem-4x2-128.vci \
    quantizado/imagem-4x2-144.vci \
    quantizado/imagem-4x2-16.vci \
    quantizado/imagem-4x2-160.vci \
    quantizado/imagem-4x2-176.vci \
    quantizado/imagem-4x2-192.vci \
    quantizado/imagem-4x2-208.vci \
    quantizado/imagem-4x2-224.vci \
    quantizado/imagem-4x2-240.vci \
    quantizado/imagem-4x2-256.vci \
    quantizado/imagem-4x2-272.vci \
    quantizado/imagem-4x2-288.vci \
    quantizado/imagem-4x2-304.vci \
    quantizado/imagem-4x2-320.vci \
    quantizado/imagem-4x2-336.vci \
    quantizado/imagem-4x2-64.vci \
    quantizado/imagem-4x2-80.vci \
    quantizado/imagem-4x2-96.vci \
    quantizado/imagem-4x4-112.vci \
    quantizado/imagem-4x4-128.vci \
    quantizado/imagem-4x4-144.vci \
    quantizado/imagem-4x4-16.vci \
    quantizado/imagem-4x4-160.vci \
    quantizado/imagem-4x4-176.vci \
    quantizado/imagem-4x4-192.vci \
    quantizado/imagem-4x4-208.vci \
    quantizado/imagem-4x4-224.vci \
    quantizado/imagem-4x4-240.vci \
    quantizado/imagem-4x4-256.vci \
    quantizado/imagem-4x4-272.vci \
    quantizado/imagem-4x4-288.vci \
    quantizado/imagem-4x4-304.vci \
    quantizado/imagem-4x4-32.vci \
    quantizado/imagem-4x4-320.vci \
    quantizado/imagem-4x4-336.vci \
    quantizado/imagem-4x4-48.vci \
    quantizado/imagem-4x4-64.vci \
    quantizado/imagem-4x4-80.vci \
    quantizado/imagem-4x4-96.vci \
    VectorQuantizer-LBG \
    imagens/casal.tiff \
    imagens/lena.tiff \
    imagens/monkey.tiff \
    imagens/relogio.tiff \
    imagens/teatro.tiff \
    quantizado/imagem-1x2-112.tiff \
    quantizado/imagem-1x2-128.tiff \
    quantizado/imagem-1x2-144.tiff \
    quantizado/imagem-1x2-16.tiff \
    quantizado/imagem-1x2-160.tiff \
    quantizado/imagem-1x2-176.tiff \
    quantizado/imagem-1x2-192.tiff \
    quantizado/imagem-1x2-208.tiff \
    quantizado/imagem-1x2-224.tiff \
    quantizado/imagem-1x2-240.tiff \
    quantizado/imagem-1x2-256.tiff \
    quantizado/imagem-1x2-272.tiff \
    quantizado/imagem-1x2-288.tiff \
    quantizado/imagem-1x2-304.tiff \
    quantizado/imagem-1x2-32.tiff \
    quantizado/imagem-1x2-320.tiff \
    quantizado/imagem-1x2-336.tiff \
    quantizado/imagem-1x2-48.tiff \
    quantizado/imagem-1x2-64.tiff \
    quantizado/imagem-1x2-80.tiff \
    quantizado/imagem-1x2-96.tiff \
    quantizado/imagem-2x2-112.tiff \
    quantizado/imagem-2x2-128.tiff \
    quantizado/imagem-2x2-144.tiff \
    quantizado/imagem-2x2-16.tiff \
    quantizado/imagem-2x2-160.tiff \
    quantizado/imagem-2x2-176.tiff \
    quantizado/imagem-2x2-192.tiff \
    quantizado/imagem-2x2-208.tiff \
    quantizado/imagem-2x2-224.tiff \
    quantizado/imagem-2x2-240.tiff \
    quantizado/imagem-2x2-256.tiff \
    quantizado/imagem-2x2-272.tiff \
    quantizado/imagem-2x2-288.tiff \
    quantizado/imagem-2x2-304.tiff \
    quantizado/imagem-2x2-32.tiff \
    quantizado/imagem-2x2-320.tiff \
    quantizado/imagem-2x2-336.tiff \
    quantizado/imagem-2x2-48.tiff \
    quantizado/imagem-2x2-64.tiff \
    quantizado/imagem-2x2-80.tiff \
    quantizado/imagem-2x2-96.tiff \
    quantizado/imagem-2x4-112.tiff \
    quantizado/imagem-2x4-128.tiff \
    quantizado/imagem-2x4-144.tiff \
    quantizado/imagem-2x4-16.tiff \
    quantizado/imagem-2x4-160.tiff \
    quantizado/imagem-2x4-176.tiff \
    quantizado/imagem-2x4-192.tiff \
    quantizado/imagem-2x4-208.tiff \
    quantizado/imagem-2x4-224.tiff \
    quantizado/imagem-2x4-240.tiff \
    quantizado/imagem-2x4-256.tiff \
    quantizado/imagem-2x4-272.tiff \
    quantizado/imagem-2x4-288.tiff \
    quantizado/imagem-2x4-304.tiff \
    quantizado/imagem-2x4-32.tiff \
    quantizado/imagem-2x4-320.tiff \
    quantizado/imagem-2x4-336.tiff \
    quantizado/imagem-2x4-48.tiff \
    quantizado/imagem-2x4-64.tiff \
    quantizado/imagem-2x4-80.tiff \
    quantizado/imagem-2x4-96.tiff \
    quantizado/imagem-4x2-112.tiff \
    quantizado/imagem-4x2-128.tiff \
    quantizado/imagem-4x2-144.tiff \
    quantizado/imagem-4x2-16.tiff \
    quantizado/imagem-4x2-160.tiff \
    quantizado/imagem-4x2-176.tiff \
    quantizado/imagem-4x2-192.tiff \
    quantizado/imagem-4x2-208.tiff \
    quantizado/imagem-4x2-224.tiff \
    quantizado/imagem-4x2-240.tiff \
    quantizado/imagem-4x2-256.tiff \
    quantizado/imagem-4x2-272.tiff \
    quantizado/imagem-4x2-288.tiff \
    quantizado/imagem-4x2-304.tiff \
    quantizado/imagem-4x2-32.tiff \
    quantizado/imagem-4x2-320.tiff \
    quantizado/imagem-4x2-336.tiff \
    quantizado/imagem-4x2-48.tiff \
    quantizado/imagem-4x2-64.tiff \
    quantizado/imagem-4x2-80.tiff \
    quantizado/imagem-4x2-96.tiff \
    quantizado/imagem-4x4-112.tiff \
    quantizado/imagem-4x4-128.tiff \
    quantizado/imagem-4x4-144.tiff \
    quantizado/imagem-4x4-16.tiff \
    quantizado/imagem-4x4-160.tiff \
    quantizado/imagem-4x4-176.tiff \
    quantizado/imagem-4x4-192.tiff \
    quantizado/imagem-4x4-208.tiff \
    quantizado/imagem-4x4-224.tiff \
    quantizado/imagem-4x4-240.tiff \
    quantizado/imagem-4x4-256.tiff \
    quantizado/imagem-4x4-272.tiff \
    quantizado/imagem-4x4-288.tiff \
    quantizado/imagem-4x4-304.tiff \
    quantizado/imagem-4x4-32.tiff \
    quantizado/imagem-4x4-320.tiff \
    quantizado/imagem-4x4-336.tiff \
    quantizado/imagem-4x4-48.tiff \
    quantizado/imagem-4x4-64.tiff \
    quantizado/imagem-4x4-80.tiff \
    quantizado/imagem-4x4-96.tiff \
    quantizado/imagem-4x2-32.vci \
    quantizado/imagem-4x2-48.vci \
    README.md \
    codebooks/codebook-2x4-128.cdbk \
    codebooks/codebook-4x2-112.cdbk \
    codebooks/codebook-4x2-128.cdbk \
    codebooks/codebook-4x2-144.cdbk \
    codebooks/codebook-4x2-160.cdbk \
    codebooks/codebook-4x2-192.cdbk \
    codebooks/codebook-4x2-208.cdbk \
    codebooks/codebook-4x2-224.cdbk \
    codebooks/codebook-4x2-240.cdbk \
    codebooks/codebook-4x2-256.cdbk \
    codebooks/codebook-4x2-272.cdbk \
    codebooks/codebook-4x2-288.cdbk \
    codebooks/codebook-4x2-304.cdbk \
    codebooks/codebook-4x2-32.cdbk \
    codebooks/codebook-4x2-80.cdbk \
    codebooks/codebook-4x2-96.cdbk \
    codebooks/codebook-4x4-112.cdbk \
    codebooks/codebook-4x4-128.cdbk \
    codebooks/codebook-4x4-144.cdbk \
    codebooks/codebook-4x4-160.cdbk \
    codebooks/codebook-4x4-240.cdbk \
    codebooks/codebook-4x4-256.cdbk \
    codebooks/codebook-4x4-32.cdbk \
    codebooks/codebook-4x4-336.cdbk \
    codebooks/codebook-4x4-48.cdbk \
    codebooks/codebook-4x4-64.cdbk \
    codebooks/codebook-4x4-80.cdbk \
    codebooks/codebook-4x4-96.cdbk \
    quantizado/imagem-1x2-160.vci \
    quantizado/imagem-1x2-176.vci \
    quantizado/imagem-1x2-96.vci \
    quantizado/imagem-2x2-112.vci \
    quantizado/imagem-2x2-128.vci \
    quantizado/imagem-2x2-144.vci \
    quantizado/imagem-2x2-240.vci \
    quantizado/imagem-2x2-256.vci \
    quantizado/imagem-2x2-96.vci \
    LICENSE \
    codebooks/codebook-2x2-240.cdbk \
    codebooks/codebook-1x2-112.cdbk \
    codebooks/codebook-1x2-128.cdbk \
    codebooks/codebook-1x2-144.cdbk \
    codebooks/codebook-1x2-16.cdbk \
    codebooks/codebook-1x2-160.cdbk \
    codebooks/codebook-1x2-176.cdbk \
    codebooks/codebook-1x2-192.cdbk \
    codebooks/codebook-1x2-208.cdbk \
    codebooks/codebook-1x2-224.cdbk \
    codebooks/codebook-1x2-240.cdbk \
    codebooks/codebook-1x2-256.cdbk \
    codebooks/codebook-1x2-272.cdbk \
    codebooks/codebook-1x2-288.cdbk \
    codebooks/codebook-1x2-304.cdbk \
    codebooks/codebook-1x2-32.cdbk \
    codebooks/codebook-1x2-320.cdbk \
    codebooks/codebook-1x2-336.cdbk \
    codebooks/codebook-1x2-48.cdbk \
    codebooks/codebook-1x2-64.cdbk \
    codebooks/codebook-1x2-80.cdbk \
    codebooks/codebook-1x2-96.cdbk \
    codebooks/codebook-2x2-112.cdbk \
    codebooks/codebook-2x2-128.cdbk \
    codebooks/codebook-2x2-144.cdbk \
    codebooks/codebook-2x2-16.cdbk \
    codebooks/codebook-2x2-160.cdbk \
    codebooks/codebook-2x2-176.cdbk \
    codebooks/codebook-2x2-192.cdbk \
    codebooks/codebook-2x2-208.cdbk \
    codebooks/codebook-2x2-224.cdbk \
    codebooks/codebook-2x2-256.cdbk \
    codebooks/codebook-2x2-272.cdbk \
    codebooks/codebook-2x2-288.cdbk \
    codebooks/codebook-2x2-304.cdbk \
    codebooks/codebook-2x2-32.cdbk \
    codebooks/codebook-2x2-320.cdbk \
    codebooks/codebook-2x2-336.cdbk \
    codebooks/codebook-2x2-48.cdbk \
    codebooks/codebook-2x2-64.cdbk \
    codebooks/codebook-2x2-80.cdbk \
    codebooks/codebook-2x2-96.cdbk \
    codebooks/codebook-2x4-112.cdbk \
    codebooks/codebook-2x4-144.cdbk \
    codebooks/codebook-2x4-16.cdbk \
    codebooks/codebook-2x4-160.cdbk \
    codebooks/codebook-2x4-176.cdbk \
    codebooks/codebook-2x4-192.cdbk \
    codebooks/codebook-2x4-208.cdbk \
    codebooks/codebook-2x4-224.cdbk \
    codebooks/codebook-2x4-240.cdbk \
    codebooks/codebook-2x4-256.cdbk \
    codebooks/codebook-2x4-272.cdbk \
    codebooks/codebook-2x4-288.cdbk \
    codebooks/codebook-2x4-304.cdbk \
    codebooks/codebook-2x4-32.cdbk \
    codebooks/codebook-2x4-320.cdbk \
    codebooks/codebook-2x4-336.cdbk \
    codebooks/codebook-2x4-48.cdbk \
    codebooks/codebook-2x4-64.cdbk \
    codebooks/codebook-2x4-80.cdbk \
    codebooks/codebook-2x4-96.cdbk \
    codebooks/codebook-4x2-16.cdbk \
    codebooks/codebook-4x2-176.cdbk \
    codebooks/codebook-4x2-320.cdbk \
    codebooks/codebook-4x2-336.cdbk \
    codebooks/codebook-4x2-48.cdbk \
    codebooks/codebook-4x2-64.cdbk \
    codebooks/codebook-4x4-16.cdbk \
    codebooks/codebook-4x4-176.cdbk \
    codebooks/codebook-4x4-192.cdbk \
    codebooks/codebook-4x4-208.cdbk \
    codebooks/codebook-4x4-224.cdbk \
    codebooks/codebook-4x4-272.cdbk \
    codebooks/codebook-4x4-288.cdbk \
    codebooks/codebook-4x4-304.cdbk \
    codebooks/codebook-4x4-320.cdbk \
    quantizado/imagem-1x2-112.vci \
    quantizado/imagem-1x2-128.vci \
    quantizado/imagem-1x2-144.vci \
    quantizado/imagem-1x2-16.vci \
    quantizado/imagem-1x2-192.vci \
    quantizado/imagem-1x2-208.vci \
    quantizado/imagem-1x2-224.vci \
    quantizado/imagem-1x2-240.vci \
    quantizado/imagem-1x2-256.vci \
    quantizado/imagem-1x2-272.vci \
    quantizado/imagem-1x2-288.vci \
    quantizado/imagem-1x2-304.vci \
    quantizado/imagem-1x2-32.vci \
    quantizado/imagem-1x2-320.vci \
    quantizado/imagem-1x2-336.vci \
    quantizado/imagem-1x2-48.vci \
    quantizado/imagem-1x2-64.vci \
    quantizado/imagem-1x2-80.vci \
    quantizado/imagem-2x2-16.vci \
    quantizado/imagem-2x2-160.vci \
    quantizado/imagem-2x2-176.vci \
    quantizado/imagem-2x2-192.vci \
    quantizado/imagem-2x2-208.vci \
    quantizado/imagem-2x2-224.vci \
    quantizado/imagem-2x2-272.vci \
    quantizado/imagem-2x2-288.vci \
    quantizado/imagem-2x2-304.vci \
    quantizado/imagem-2x2-32.vci \
    quantizado/imagem-2x2-320.vci \
    quantizado/imagem-2x2-336.vci \
    quantizado/imagem-2x2-48.vci \
    quantizado/imagem-2x2-64.vci \
    quantizado/imagem-2x2-80.vci \
    quantizado/imagem-2x4-112.vci \
    quantizado/imagem-2x4-128.vci \
    quantizado/imagem-2x4-144.vci \
    quantizado/imagem-2x4-16.vci \
    quantizado/imagem-2x4-160.vci \
    quantizado/imagem-2x4-176.vci \
    quantizado/imagem-2x4-192.vci \
    quantizado/imagem-2x4-208.vci \
    quantizado/imagem-2x4-224.vci \
    quantizado/imagem-2x4-240.vci \
    quantizado/imagem-2x4-256.vci \
    quantizado/imagem-2x4-272.vci \
    quantizado/imagem-2x4-288.vci \
    quantizado/imagem-2x4-304.vci \
    quantizado/imagem-2x4-32.vci \
    quantizado/imagem-2x4-320.vci \
    quantizado/imagem-2x4-336.vci \
    quantizado/imagem-2x4-48.vci \
    quantizado/imagem-2x4-64.vci \
    quantizado/imagem-2x4-80.vci \
    quantizado/imagem-2x4-96.vci \
    quantizado/imagem-4x2-112.vci \
    quantizado/imagem-4x2-128.vci \
    quantizado/imagem-4x2-144.vci \
    quantizado/imagem-4x2-16.vci \
    quantizado/imagem-4x2-160.vci \
    quantizado/imagem-4x2-176.vci \
    quantizado/imagem-4x2-192.vci \
    quantizado/imagem-4x2-208.vci \
    quantizado/imagem-4x2-224.vci \
    quantizado/imagem-4x2-240.vci \
    quantizado/imagem-4x2-256.vci \
    quantizado/imagem-4x2-272.vci \
    quantizado/imagem-4x2-288.vci \
    quantizado/imagem-4x2-304.vci \
    quantizado/imagem-4x2-320.vci \
    quantizado/imagem-4x2-336.vci \
    quantizado/imagem-4x2-64.vci \
    quantizado/imagem-4x2-80.vci \
    quantizado/imagem-4x2-96.vci \
    quantizado/imagem-4x4-112.vci \
    quantizado/imagem-4x4-128.vci \
    quantizado/imagem-4x4-144.vci \
    quantizado/imagem-4x4-16.vci \
    quantizado/imagem-4x4-160.vci \
    quantizado/imagem-4x4-176.vci \
    quantizado/imagem-4x4-192.vci \
    quantizado/imagem-4x4-208.vci \
    quantizado/imagem-4x4-224.vci \
    quantizado/imagem-4x4-240.vci \
    quantizado/imagem-4x4-256.vci \
    quantizado/imagem-4x4-272.vci \
    quantizado/imagem-4x4-288.vci \
    quantizado/imagem-4x4-304.vci \
    quantizado/imagem-4x4-32.vci \
    quantizado/imagem-4x4-320.vci \
    quantizado/imagem-4x4-336.vci \
    quantizado/imagem-4x4-48.vci \
    quantizado/imagem-4x4-64.vci \
    quantizado/imagem-4x4-80.vci \
    quantizado/imagem-4x4-96.vci \
    VectorQuantizer-LBG \
    imagens/casal.tiff \
    imagens/lena.tiff \
    imagens/monkey.tiff \
    imagens/relogio.tiff \
    imagens/teatro.tiff \
    quantizado/imagem-1x2-112.tiff \
    quantizado/imagem-1x2-128.tiff \
    quantizado/imagem-1x2-144.tiff \
    quantizado/imagem-1x2-16.tiff \
    quantizado/imagem-1x2-160.tiff \
    quantizado/imagem-1x2-176.tiff \
    quantizado/imagem-1x2-192.tiff \
    quantizado/imagem-1x2-208.tiff \
    quantizado/imagem-1x2-224.tiff \
    quantizado/imagem-1x2-240.tiff \
    quantizado/imagem-1x2-256.tiff \
    quantizado/imagem-1x2-272.tiff \
    quantizado/imagem-1x2-288.tiff \
    quantizado/imagem-1x2-304.tiff \
    quantizado/imagem-1x2-32.tiff \
    quantizado/imagem-1x2-320.tiff \
    quantizado/imagem-1x2-336.tiff \
    quantizado/imagem-1x2-48.tiff \
    quantizado/imagem-1x2-64.tiff \
    quantizado/imagem-1x2-80.tiff \
    quantizado/imagem-1x2-96.tiff \
    quantizado/imagem-2x2-112.tiff \
    quantizado/imagem-2x2-128.tiff \
    quantizado/imagem-2x2-144.tiff \
    quantizado/imagem-2x2-16.tiff \
    quantizado/imagem-2x2-160.tiff \
    quantizado/imagem-2x2-176.tiff \
    quantizado/imagem-2x2-192.tiff \
    quantizado/imagem-2x2-208.tiff \
    quantizado/imagem-2x2-224.tiff \
    quantizado/imagem-2x2-240.tiff \
    quantizado/imagem-2x2-256.tiff \
    quantizado/imagem-2x2-272.tiff \
    quantizado/imagem-2x2-288.tiff \
    quantizado/imagem-2x2-304.tiff \
    quantizado/imagem-2x2-32.tiff \
    quantizado/imagem-2x2-320.tiff \
    quantizado/imagem-2x2-336.tiff \
    quantizado/imagem-2x2-48.tiff \
    quantizado/imagem-2x2-64.tiff \
    quantizado/imagem-2x2-80.tiff \
    quantizado/imagem-2x2-96.tiff \
    quantizado/imagem-2x4-112.tiff \
    quantizado/imagem-2x4-128.tiff \
    quantizado/imagem-2x4-144.tiff \
    quantizado/imagem-2x4-16.tiff \
    quantizado/imagem-2x4-160.tiff \
    quantizado/imagem-2x4-176.tiff \
    quantizado/imagem-2x4-192.tiff \
    quantizado/imagem-2x4-208.tiff \
    quantizado/imagem-2x4-224.tiff \
    quantizado/imagem-2x4-240.tiff \
    quantizado/imagem-2x4-256.tiff \
    quantizado/imagem-2x4-272.tiff \
    quantizado/imagem-2x4-288.tiff \
    quantizado/imagem-2x4-304.tiff \
    quantizado/imagem-2x4-32.tiff \
    quantizado/imagem-2x4-320.tiff \
    quantizado/imagem-2x4-336.tiff \
    quantizado/imagem-2x4-48.tiff \
    quantizado/imagem-2x4-64.tiff \
    quantizado/imagem-2x4-80.tiff \
    quantizado/imagem-2x4-96.tiff \
    quantizado/imagem-4x2-112.tiff \
    quantizado/imagem-4x2-128.tiff \
    quantizado/imagem-4x2-144.tiff \
    quantizado/imagem-4x2-16.tiff \
    quantizado/imagem-4x2-160.tiff \
    quantizado/imagem-4x2-176.tiff \
    quantizado/imagem-4x2-192.tiff \
    quantizado/imagem-4x2-208.tiff \
    quantizado/imagem-4x2-224.tiff \
    quantizado/imagem-4x2-240.tiff \
    quantizado/imagem-4x2-256.tiff \
    quantizado/imagem-4x2-272.tiff \
    quantizado/imagem-4x2-288.tiff \
    quantizado/imagem-4x2-304.tiff \
    quantizado/imagem-4x2-32.tiff \
    quantizado/imagem-4x2-320.tiff \
    quantizado/imagem-4x2-336.tiff \
    quantizado/imagem-4x2-48.tiff \
    quantizado/imagem-4x2-64.tiff \
    quantizado/imagem-4x2-80.tiff \
    quantizado/imagem-4x2-96.tiff \
    quantizado/imagem-4x4-112.tiff \
    quantizado/imagem-4x4-128.tiff \
    quantizado/imagem-4x4-144.tiff \
    quantizado/imagem-4x4-16.tiff \
    quantizado/imagem-4x4-160.tiff \
    quantizado/imagem-4x4-176.tiff \
    quantizado/imagem-4x4-192.tiff \
    quantizado/imagem-4x4-208.tiff \
    quantizado/imagem-4x4-224.tiff \
    quantizado/imagem-4x4-240.tiff \
    quantizado/imagem-4x4-256.tiff \
    quantizado/imagem-4x4-272.tiff \
    quantizado/imagem-4x4-288.tiff \
    quantizado/imagem-4x4-304.tiff \
    quantizado/imagem-4x4-32.tiff \
    quantizado/imagem-4x4-320.tiff \
    quantizado/imagem-4x4-336.tiff \
    quantizado/imagem-4x4-48.tiff \
    quantizado/imagem-4x4-64.tiff \
    quantizado/imagem-4x4-80.tiff \
    quantizado/imagem-4x4-96.tiff \
    quantizado/imagem-4x2-32.vci \
    quantizado/imagem-4x2-48.vci \
    README.md \
    codebooks/codebook-2x4-128.cdbk \
    codebooks/codebook-4x2-112.cdbk \
    codebooks/codebook-4x2-128.cdbk \
    codebooks/codebook-4x2-144.cdbk \
    codebooks/codebook-4x2-160.cdbk \
    codebooks/codebook-4x2-192.cdbk \
    codebooks/codebook-4x2-208.cdbk \
    codebooks/codebook-4x2-224.cdbk \
    codebooks/codebook-4x2-240.cdbk \
    codebooks/codebook-4x2-256.cdbk \
    codebooks/codebook-4x2-272.cdbk \
    codebooks/codebook-4x2-288.cdbk \
    codebooks/codebook-4x2-304.cdbk \
    codebooks/codebook-4x2-32.cdbk \
    codebooks/codebook-4x2-80.cdbk \
    codebooks/codebook-4x2-96.cdbk \
    codebooks/codebook-4x4-112.cdbk \
    codebooks/codebook-4x4-128.cdbk \
    codebooks/codebook-4x4-144.cdbk \
    codebooks/codebook-4x4-160.cdbk \
    codebooks/codebook-4x4-240.cdbk \
    codebooks/codebook-4x4-256.cdbk \
    codebooks/codebook-4x4-32.cdbk \
    codebooks/codebook-4x4-336.cdbk \
    codebooks/codebook-4x4-48.cdbk \
    codebooks/codebook-4x4-64.cdbk \
    codebooks/codebook-4x4-80.cdbk \
    codebooks/codebook-4x4-96.cdbk \
    quantizado/imagem-1x2-160.vci \
    quantizado/imagem-1x2-176.vci \
    quantizado/imagem-1x2-96.vci \
    quantizado/imagem-2x2-112.vci \
    quantizado/imagem-2x2-128.vci \
    quantizado/imagem-2x2-144.vci \
    quantizado/imagem-2x2-240.vci \
    quantizado/imagem-2x2-256.vci \
    quantizado/imagem-2x2-96.vci \
    LICENSE \
    codebooks/codebook-2x2-240.cdbk

HEADERS += \
    vectorquantizer.h \
    vectorquantizer.h \
    vectorquantizer.h

INCLUDEPATH += \
    /usr/local/include/opencv

LIBS += \
    -L/usr/local/lib \
    -lopencv_core \
    -lopencv_imgcodecs \
    -lopencv_highgui \
    -lopencv_imgproc 
#    -lopencv_stitching \
#    -lopencv_superres \
#    -lopencv_videostab \
#    -lopencv_aruco \
#    -lopencv_bgsegm \
#    -lopencv_bioinspired \
#    -lopencv_ccalib \
#    -lopencv_dnn_objdetect \
#    -lopencv_dpm \
#    -lopencv_face \
#    -lopencv_photo \
#    -lopencv_freetype \
#    -lopencv_fuzzy \
#    -lopencv_hfs \
#    -lopencv_img_hash \
#    -lopencv_line_descriptor \
#    -lopencv_optflow \
#    -lopencv_reg \
#    -lopencv_rgbd \
#    -lopencv_saliency \
#    -lopencv_stereo \
#    -lopencv_structured_light \
#    -lopencv_phase_unwrapping \
#    -lopencv_surface_matching \
#    -lopencv_tracking \
#    -lopencv_datasets \
#    -lopencv_text \
#    -lopencv_dnn \
#    -lopencv_plot \
#    -lopencv_xfeatures2d \
#    -lopencv_shape \
#    -lopencv_video \
#    -lopencv_ml \
#    -lopencv_ximgproc \
#    -lopencv_calib3d \
#    -lopencv_features2d \
#    -lopencv_videoio \
#    -lopencv_flann \
#    -lopencv_xobjdetect \
#    -lopencv_objdetect \
#    -lopencv_xphoto

SUBDIRS += \
    VectorQuantizer-LBG.pro \
    VectorQuantizer-LBG.pro
