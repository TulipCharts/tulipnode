declare module "tulind" {
  /**
   * Tulip indicators
   */
  export const indicators: Record<string, Indicator>;

  /**
   * Tulip indicators version
   */
  export const version: string;

  /**
   * Indicator types
   */
  export type IndicatorType =
    | "overlay"
    | "indicator"
    | "math"
    | "simple"
    | "comparative";

  export interface Indicator {
    name: string;
    full_name: string;
    type: IndicatorType;
    inputs: number;
    options: number;
    outputs: number;
    input_names: string[];
    option_names: string[];
    output_names: string[];

    /**
     * Given these options, the output array will be this much
     * short than the input arrays.
     * @param options
     */
    start(options: any[]): number;

    /**
     * Indicator function
     * @param inputs
     * @param options
     * @param cb
     */
    indicator(
      inputs: any[],
      options: any[],
      cb: (err: Error | undefined, results: any[]) => void
    ): void;
  }
}
