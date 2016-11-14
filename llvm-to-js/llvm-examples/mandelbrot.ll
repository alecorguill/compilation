; ModuleID = 'mandelbrot.o'
target datalayout = "e-p:32:32-i64:64-v128:32:128-n32-S128"
target triple = "asmjs-unknown-emscripten"

declare void @createCanvas(i32, i32)
declare double @log10(double)
declare void @stroke(i32)
declare void @point(i32, i32)

@WIDTH = common global float 0.000000e+00
@HEIGHT = common global float 0.000000e+00
@START_ZOOM = common global float 0.000000e+00
@BAIL_OUT = common global float 0.000000e+00
@ZOOM_FACTOR = common global float 0.000000e+00
@zoom = common global float 0.000000e+00

; Function Attrs: nounwind
define void @my_setup() {
  store float 6.400000e+02, float* @WIDTH
  store float 4.800000e+02, float* @HEIGHT
  %1 = load float, float* @WIDTH
  %2 = fmul float %1, 0x3FD030A3E0000000
  store float %2, float* @START_ZOOM
  store float 2.000000e+00, float* @BAIL_OUT
  store float 0x3FF6666660000000, float* @ZOOM_FACTOR
  %3 = load float, float* @WIDTH
  %4 = fptosi float %3 to i32
  %5 = load float, float* @HEIGHT
  %6 = fptosi float %5 to i32
  call void @createCanvas(i32 %4, i32 %6)
  %7 = load float, float* @START_ZOOM
  store float %7, float* @zoom
  ret void
}

; Function Attrs: nounwind
define void @my_draw() {
  %1 = alloca i32
  %2 = alloca i32
  %3 = alloca i32
  %4 = alloca i32
  %5 = alloca float
  %6 = alloca float
  %7 = alloca float
  %8 = alloca float
  %9 = alloca float
  %10 = alloca float
  %11 = alloca float
  %12 = alloca float
  %13 = alloca float
  %14 = alloca i32
  %15 = load float, float* @WIDTH
  %16 = fdiv float %15, 2.000000e+00
  %17 = fpext float %16 to double
  %18 = fmul double %17, 0x3FA9745D167DE830
  %19 = load float, float* @zoom
  %20 = fpext float %19 to double
  %21 = call double @log10(double %20)
  %22 = fmul double %18, %21
  %23 = fptosi double %22 to i32
  store i32 %23, i32* %4
  store float 0xBFE99F18C0000000, float* %9
  store float 0x3FC4463060000000, float* %10
  store i32 0, i32* %2
  br label %24

; <label>:24:                                     ; preds = %115, %0
  %25 = load i32, i32* %2
  %26 = sitofp i32 %25 to float
  %27 = load float, float* @HEIGHT
  %28 = fcmp olt float %26, %27
  br i1 %28, label %29, label %118

; <label>:29:                                     ; preds = %24
  store i32 0, i32* %1
  br label %30

; <label>:30:                                     ; preds = %111, %29
  %31 = load i32, i32* %1
  %32 = sitofp i32 %31 to float
  %33 = load float, float* @WIDTH
  %34 = fcmp olt float %32, %33
  br i1 %34, label %35, label %114

; <label>:35:                                     ; preds = %30
  store float 0.000000e+00, float* %11
  %36 = load float, float* %9
  %37 = load i32, i32* %1
  %38 = sitofp i32 %37 to float
  %39 = load float, float* @WIDTH
  %40 = fdiv float %39, 2.000000e+00
  %41 = fsub float %38, %40
  %42 = load float, float* @zoom
  %43 = fdiv float %41, %42
  %44 = fadd float %36, %43
  store float %44, float* %7
  store float %44, float* %5
  %45 = load float, float* %10
  %46 = load i32, i32* %2
  %47 = sitofp i32 %46 to float
  %48 = load float, float* @HEIGHT
  %49 = fdiv float %48, 2.000000e+00
  %50 = fsub float %47, %49
  %51 = load float, float* @zoom
  %52 = fdiv float %50, %51
  %53 = fadd float %45, %52
  store float %53, float* %8
  store float %53, float* %6
  store i32 0, i32* %3
  br label %54

; <label>:54:                                     ; preds = %91, %35
  %55 = load i32, i32* %3
  %56 = load i32, i32* %4
  %57 = icmp sle i32 %55, %56
  br i1 %57, label %58, label %64

; <label>:58:                                     ; preds = %54
  %59 = load float, float* %11
  %60 = load float, float* @BAIL_OUT
  %61 = load float, float* @BAIL_OUT
  %62 = fmul float %60, %61
  %63 = fcmp olt float %59, %62
  br label %64

; <label>:64:                                     ; preds = %58, %54
  %65 = phi i1 [ false, %54 ], [ %63, %58 ]
  br i1 %65, label %66, label %94

; <label>:66:                                     ; preds = %64
  %67 = load float, float* %5
  %68 = load float, float* %5
  %69 = fmul float %67, %68
  %70 = load float, float* %6
  %71 = load float, float* %6
  %72 = fmul float %70, %71
  %73 = fsub float %69, %72
  %74 = load float, float* %7
  %75 = fadd float %73, %74
  store float %75, float* %12
  %76 = load float, float* %5
  %77 = fmul float 2.000000e+00, %76
  %78 = load float, float* %6
  %79 = fmul float %77, %78
  %80 = load float, float* %8
  %81 = fadd float %79, %80
  store float %81, float* %13
  %82 = load float, float* %12
  store float %82, float* %5
  %83 = load float, float* %13
  store float %83, float* %6
  %84 = load float, float* %12
  %85 = load float, float* %12
  %86 = fmul float %84, %85
  %87 = load float, float* %13
  %88 = load float, float* %13
  %89 = fmul float %87, %88
  %90 = fadd float %86, %89
  store float %90, float* %11
  br label %91

; <label>:91:                                     ; preds = %66
  %92 = load i32, i32* %3
  %93 = add nsw i32 %92, 1
  store i32 %93, i32* %3
  br label %54

; <label>:94:                                     ; preds = %64
  %95 = load i32, i32* %3
  %96 = load i32, i32* %4
  %97 = icmp slt i32 %95, %96
  br i1 %97, label %98, label %106

; <label>:98:                                     ; preds = %94
  %99 = load i32, i32* %3
  %100 = sitofp i32 %99 to float
  %101 = load i32, i32* %4
  %102 = sitofp i32 %101 to float
  %103 = fdiv float %100, %102
  %104 = fmul float %103, 2.550000e+02
  %105 = fptosi float %104 to i32
  store i32 %105, i32* %14
  br label %107

; <label>:106:                                    ; preds = %94
  store i32 0, i32* %14
  br label %107

; <label>:107:                                    ; preds = %106, %98
  %108 = load i32, i32* %14
  call void @stroke(i32 %108)
  %109 = load i32, i32* %1
  %110 = load i32, i32* %2
  call void @point(i32 %109, i32 %110)
  br label %111

; <label>:111:                                    ; preds = %107
  %112 = load i32, i32* %1
  %113 = add nsw i32 %112, 1
  store i32 %113, i32* %1
  br label %30

; <label>:114:                                    ; preds = %30
  br label %115

; <label>:115:                                    ; preds = %114
  %116 = load i32, i32* %2
  %117 = add nsw i32 %116, 1
  store i32 %117, i32* %2
  br label %24

; <label>:118:                                    ; preds = %24
  %119 = load float, float* @ZOOM_FACTOR
  %120 = load float, float* @zoom
  %121 = fmul float %120, %119
  store float %121, float* @zoom
  ret void
}


